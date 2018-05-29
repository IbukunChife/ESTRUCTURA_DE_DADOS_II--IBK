//
// Created by WizIbk on 27/05/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arv.h"

Btree *Criar_ArvoreB(unsigned int ordem) {
    Btree *btree = (Btree *) malloc(sizeof(Btree));
    btree->ORDEM = ordem;
    btree->raiz = Criar_Pagina(ordem);
    return btree;
}

static Pagina *Criar_Pagina(unsigned int ordem) {

    Pagina *node = (Pagina *) malloc(sizeof(Pagina));
    node->num = 0;
    node->chaves = (int *) malloc((ordem - 1) * sizeof(int));
    node->filhos = (Pagina **) malloc(ordem * sizeof(Pagina *));
    node->folha = true;
    node->nivel = 0;
    return node;
}

static void Split_filhos(Btree *btree, Pagina *Pai, int index, Pagina *fil) {
    int i = 0;
    unsigned int order = btree->ORDEM;
    unsigned int meio = order / 2;

    Pagina *irmao = Criar_Pagina(order);
    irmao->folha = fil->folha;
    irmao->nivel = fil->nivel;
    irmao->num = (order / 2) - 1;

    // Copie as chaves de maior ordem para o novo filho
    for (i = 0; i < irmao->num; i++) {
        irmao->chaves[i] = fil->chaves[i + meio];
        if (!fil->folha) {
            irmao->filhos[i] =
                    fil->filhos[i + meio];
        }
    }

    // Copie o último ponteiro filho
    if (!fil->folha) {
        irmao->filhos[i] =
                fil->filhos[i + meio];
    }

    fil->num = meio - 1;

    for (i = Pai->num + 1; i > index + 1; i--) {
        Pai->filhos[i] = Pai->filhos[i - 1];
    }
    Pai->filhos[index + 1] = irmao;

    for (i = Pai->num; i > index; i--) {
        Pai->chaves[i] = Pai->chaves[i - 1];
    }

    Pai->chaves[index] = fil->chaves[meio - 1];
    Pai->num++;

}

static void Insert_naoCheia(Btree *btree, Pagina *Pai, int val) {

    int i;
    Pagina *fil;
    Pagina *node = Pai;

    /*   insert:*/    i = node->num - 1;
    if (node->folha) {
        while (i >= 0 && val < node->chaves[i]) {
            node->chaves[i + 1] = node->chaves[i];
            i--;
        }
        node->chaves[i + 1] = val;
        node->num++;
    } else {
        while (i >= 0 && val < node->chaves[i]) {
            i--;
        }
        i++;
        fil = node->filhos[i];

        if (fil->num == btree->ORDEM - 1) {
            Split_filhos(btree, node, i, fil);
            if (val > node->chaves[i]) {
                i++;
            }
        }
        Insert_naoCheia(btree, node->filhos[i], val);
        // node = node->filhos[i];
        // goto insert;
    }
}

int Insert_Chave(Btree *btree, int key) {
    Pagina *rnode;

    rnode = btree->raiz;
    if (rnode->num == (btree->ORDEM - 1)) {
        Pagina *novo_raiz;
        novo_raiz = Criar_Pagina(btree->ORDEM);
        novo_raiz->nivel = btree->raiz->nivel + 1;
        btree->raiz = novo_raiz;
        novo_raiz->folha = false;
        novo_raiz->num = 0;
        novo_raiz->filhos[0] = rnode;
        Split_filhos(btree, novo_raiz, 0, rnode);
        Insert_naoCheia(btree, novo_raiz, key);
    } else
        Insert_naoCheia(btree, rnode, key);

    return 0;
}
/// MERGE NODO N1 E N2 (CASO 3b DE Cormen)

static Pagina *merge_irmao(Btree *btree, Pagina *Pai, unsigned int index, position_t pos) {
    int i, j;
    Pagina *novo;
    Pagina *n1, *n2;
    int meio = btree->ORDEM / 2;

    if (index == Pai->num) {
        index--;
        n1 = Pai->filhos[Pai->num - 1];
        n2 = Pai->filhos[Pai->num];
    } else {
        n1 = Pai->filhos[index];
        n2 = Pai->filhos[index + 1];
    }

    ///Merge do atual nodo com o nodo que esta na sua esquerda
    novo = Criar_Pagina(btree->ORDEM);
    novo->nivel = n1->nivel;
    novo->folha = n1->folha;

    for (j = 0; j < meio - 1; j++) {
        novo->chaves[j] = n1->chaves[j];
        novo->filhos[j] = n1->filhos[j];
    }

    novo->chaves[meio - 1] = Pai->chaves[index];
    novo->filhos[meio - 1] = n1->filhos[meio - 1];

    for (j = 0; j < meio - 1; j++) {
        novo->chaves[j + meio] = n2->chaves[j];
        novo->filhos[j + meio] = n2->filhos[j];
    }
    novo->filhos[btree->ORDEM - 1] = n2->filhos[meio - 1];

    Pai->filhos[index] = novo;

    for (j = index; j < Pai->num; j++) {
        Pai->chaves[j] = Pai->chaves[j + 1];
        Pai->filhos[j + 1] = Pai->filhos[j + 2];
    }

    novo->num = n1->num + n2->num + 1;
    Pai->num--;

    for (i = Pai->num; i < btree->ORDEM; i++) {
        Pai->chaves[i] = NULL;
    }

    Liberar_Pagina(n1);
    Liberar_Pagina(n2);

    if (Pai->num == 0 && btree->raiz == Pai) {
        Liberar_Pagina(Pai);
        btree->raiz = novo;
        if (novo->nivel)
            novo->folha = false;
        else
            novo->folha = true;
    }

    return novo;
}

/**
 * Mover Chave de uma pagina  para Outro
 */
static void mover_Chave(Btree *btree, Pagina *node, unsigned int index, position_t pos) {
    Pagina *Esq_child;
    Pagina *Dir_child;
     int i;

    if (pos == right) {
        index--;
    }
    Esq_child = node->filhos[index];
    Dir_child = node->filhos[index + 1];

    // Mova a chave do pai para o filho esquerdo
    if (pos == left) {
        Esq_child->chaves[Esq_child->num] = node->chaves[index];
        Esq_child->filhos[Esq_child->num + 1] = Dir_child->filhos[0];
        Dir_child->filhos[0] = NULL;
        Esq_child->num++;

        node->chaves[index] = Dir_child->chaves[0];
        Dir_child->chaves[0] = NULL;

        for (i = 0; i < Dir_child->num - 1; i++) {
            Dir_child->chaves[i] = Dir_child->chaves[i + 1];
            Dir_child->filhos[i] = Dir_child->filhos[i + 1];
        }
        Dir_child->filhos[Dir_child->num - 1] =
                Dir_child->filhos[Dir_child->num];
        Dir_child->num--;
    } else {
        // Mova a chave do pai para o filho certo
        for (i = Dir_child->num; i > 0; i--) {
            Dir_child->chaves[i] = Dir_child->chaves[i - 1];
            Dir_child->filhos[i + 1] = Dir_child->filhos[i];
        }
        Dir_child->filhos[1] = Dir_child->filhos[0];
        Dir_child->filhos[0] = NULL;

        Dir_child->chaves[0] = node->chaves[index];

        Dir_child->filhos[0] = Dir_child->filhos[Esq_child->num];
        Esq_child->filhos[Esq_child->num] = NULL;

        node->chaves[index] = Esq_child->chaves[Esq_child->num - 1];
        Esq_child->chaves[Esq_child->num - 1] = NULL;

        Esq_child->num--;
        Dir_child->num++;
    }
}

/**
*	Merge Paginas n1 and n2
*	@param n1 primeira Pagina
*	@param n2 Segunda Pagina
*	@return a combinaiçao das duas em uma Pagina só
*/
static Pagina *merge_Pagina(Btree *btree, Pagina *n1, int val, Pagina *n2) {
    Pagina *novo;
    unsigned int i;

    novo = Criar_Pagina(btree->ORDEM);
    novo->folha = true;

    for (i = 0; i < n1->num; i++) {
        novo->chaves[i] = n1->chaves[i];
        novo->filhos[i] = n1->filhos[i];
    }
    novo->filhos[n1->num] = n1->filhos[n1->num];
    novo->chaves[n1->num] = val;

    for (i = 0; i < n2->num; i++) {
        novo->chaves[i + n1->num + 1] = n2->chaves[i];
        novo->filhos[i + n1->num + 1] = n2->filhos[i];
    }
    novo->filhos[btree->ORDEM - 1] = n2->filhos[n2->num];

    novo->num = n1->num + n2->num + 1;
    novo->folha = n1->folha;
    novo->nivel = n1->nivel;

    Liberar_Pagina(n1);
    Liberar_Pagina(n2);

    return novo;
}

/**
 * Usado para procurar uma informação dentro da Arvore
 * Ele retorna o endereço da pagina inclusive o indice aonde se acha o Valor desejado
 */

Pag_pos busca_chave(Btree *btree, int val) {
    Pag_pos kp = NULL;
    int info = val;
    unsigned int i = 0;
    Pagina *node = btree->raiz;

    for (;; i = 0) {

        // Achar o indice da chave maior ou igual
        //  da chaves que estamos procurando

        while (i < node->num && info > node->chaves[i]) {
            i++;
        }

        if (i < node->num && val == node->chaves[i]) {
            kp.nodo = node;
            kp.index = i;
            return kp;
        }

        if (node->folha) {
            return kp;
        }

        node = node->filhos[i];
    }
    return kp;

}

/**
*	* Usado para excluir uma chave do nó B-tree
*/

int remove_Chave_dentro_Pagina(Btree *btree, Pag_pos *node_pos) {
    unsigned int Max_Chave = btree->ORDEM - 1;
    int i;
    Pagina *no = node_pos->nodo;

    if (no->folha == false) {
        return -1;
    }

    for (i = node_pos->index; i < Max_Chave - 1; i++) {
        no->chaves[i] = no->chaves[i + 1];
    }
    no->num--;

    if (no->num == 0) {
        Liberar_Pagina(no);
    }
    return 0;
}

/**
 * A função é usada para remover um nodo da Arvore B
 * btree A Arvore B
*  val A chave ou valor que iremos remover na Pagina
*  Subtree a sobre arvore que ieremos procurar o Valor
*/

int remover_Chave_NaArvore(Btree *btree, Pagina *subtree, int val) {
    unsigned int i, index;
    Pagina *node = NULL, *Dir_irmao, *Esq_irmao;
    Pagina *comb_node, *Pai;
    Pag_pos sub_node_pos;
    Pag_pos node_pos;
    int info1, info2;
    int kv = val;
    int meio = btree->ORDEM / 2;

    node = subtree;
    Pai = NULL;

    del_loop:
    for (i = 0;; i = 0) {

        //Se não tem nenhuma chave return -1
        if (!node->num)
            return -1;

        // Achar o indice da chave maior ou igual
        //  da chavs qu estamos procurando

        while (i < node->num && kv > node->chaves[i]) {
            i++;
        }
        index = i;

        if (i < node->num && kv == node->chaves[i]) {
            break;
        }
        if (node->folha)
            return -1;

        Pai = node;

        // obter o nodo filho
        node = node->filhos[i];


        if (node == NULL)
            return -1;

        if (index == (Pai->num)) {
            Esq_irmao = Pai->filhos[Pai->num - 1];
            Dir_irmao = NULL;
        } else if (index == 0) {
            Esq_irmao = NULL;
            Dir_irmao = Pai->filhos[1];
        } else {
            Esq_irmao = Pai->filhos[i - 1];
            Dir_irmao = Pai->filhos[i + 1];
        }

        if (node->num == meio - 1 && Pai) {
            // a  Pagina Atual tem (t - 1) chaves mas o irmao na direita tem tambem (t - 1)
            //                // chaves
            if (Dir_irmao && (Dir_irmao->num > meio - 1)) {
                mover_Chave(btree, Pai, i, left);
            } else
                // a  Pagina Atual tem (t - 1) chaves mas o irmao na esquerda tem tambem (t - 1)
                // chaves
            if (Esq_irmao && (Esq_irmao->num > meio - 1)) {
                mover_Chave(btree, Pai, i, right);
            } else
                // o irmao Esquerdo tem (t - 1) chaves
            if (Esq_irmao && (Esq_irmao->num == meio - 1)) {
                node = merge_irmao(btree, Pai, i, left);
            } else
                // o irmao Direito tem (t - 1) chaves
            if (Dir_irmao && (Dir_irmao->num == meio - 1)) {
                node = merge_irmao(btree, Pai, i, right);
            }
        }
    }

    //Case 1 :  a pagina que contem a chave é achado e é a pagina folha.
    //Inclusive a pagina folha tem as chaves maior que o ninimum requerido.
    //Simplesmente remover a chave
    if (node->folha && (node->num > meio - 1)) {
        node_pos.nodo = node;
        node_pos.index = index;
        remove_Chave_dentro_Pagina(btree, &node_pos);
        return 0;
    }

    //If the leaf node is the root permit deletion even if the number of keys is
    //less than (t - 1)
    if (node->folha && (node == btree->raiz)) {
        node_pos.nodo = node;
        node_pos.index = index;
        remove_Chave_dentro_Pagina(btree, &node_pos);
        return 0;
    }


    //Case 2: O nó que contém a chave é encontrado e é um nó interno
    if (node->folha == false) {
        if (node->filhos[index]->num > meio - 1) {
            sub_node_pos = Obter_pos_chave_max(btree, node->filhos[index]);
            info1 = sub_node_pos.nodo->chaves[sub_node_pos.index];

            info2 = info1;
            node->chaves[index] = info2;

            remover_Chave_NaArvore(btree, node->filhos[index], info1);
            if (sub_node_pos.nodo->folha == false) {
                printf("folha não achado\n");
            }
        } else if ((node->filhos[index + 1]->num > meio - 1)) {
            sub_node_pos = Obter_pos_chave_min(btree, node->filhos[index + 1]);
            info1 = sub_node_pos.nodo->chaves[sub_node_pos.index];

            info2 = info1;
            node->chaves[index] = info2;

            remover_Chave_NaArvore(btree, node->filhos[index + 1], info1);
            if (sub_node_pos.nodo->folha == false) {
                printf("folha não achado\n");
            }

        } else if (
                node->filhos[index]->num == meio - 1 && node->filhos[index + 1]->num == meio - 1) {

            comb_node = merge_Pagina(btree, node->filhos[index], node->chaves[index], node->filhos[index + 1]);
            node->filhos[index] = comb_node;

            for (i = index + 1; i < node->num; i++) {
                node->filhos[i] = node->filhos[i + 1];
                node->chaves[i - 1] = node->chaves[i];
            }
            node->num--;
            if (node->num == 0 && btree->raiz == node) {
                Liberar_Pagina(node);
                btree->raiz = comb_node;
            }
            node = comb_node;
            goto del_loop;
        }
    }

    // Case 3:
    if (node->folha && (node->num > meio - 1)) {
        node_pos.nodo = node;
        node_pos.index = index;
        remove_Chave_dentro_Pagina(btree, &node_pos);
    }

    return 0;
}

/**
 * liberar a Pagina
*/
static int Liberar_Pagina(Pagina *no) {
    free(no->filhos);
    free(no->chaves);
    free(no);
    return 0;
}

/**
 * Usado para achar a posição do Maximo valor num subArvore
*/

static Pag_pos Obter_pos_chave_max(Btree *btree, Pagina *subtree) {
    Pag_pos node_pos = NULL;
    Pagina *node = subtree;

    while (true) {
        if (node == NULL) {
            break;
        }

        if (node->folha) {
            node_pos.nodo = node;
            node_pos.index = node->num - 1;
            return node_pos;
        } else {
            node_pos.nodo = node;
            node_pos.index = node->num - 1;
            node = node->filhos[node->num];
        }
    }
    return node_pos;
}

/**
 * Usado para achar a posição do Minimo valor num subArvore
*/
static Pag_pos Obter_pos_chave_min(Btree *btree, Pagina *subtree) {
    Pag_pos node_pos = NULL;
    Pagina *node = subtree;

    while (true) {
        if (node == NULL) {
            break;
        }

        if (node->folha) {
            node_pos.nodo = node;
            node_pos.index = 0;
            return node_pos;
        } else {
            node_pos.nodo = node;
            node_pos.index = 0;
            node = node->filhos[0];
        }
    }
    return node_pos;
}

/**
* Liberar Arvore B
*/
void liberar_ArvoreB(Btree * btree) {
    int i = 0;
     int nivel_atual;

    Pagina * head, * tail, * node;
    Pagina * child, * del_node;

    node = btree->raiz;
    nivel_atual = node->nivel;
    head = node;
    tail = node;

    while(true) {
        if(head == NULL) {
            break;
        }
        if (head->nivel < nivel_atual) {
            nivel_atual = head->nivel;
        }

        if(head->folha == false) {
            for(i = 0 ; i < head->num + 1; i++) {
                child = head->filhos[i];
                tail->next = child;
                tail = child;
                child->next = NULL;
            }
        }
        del_node = head;
        head = head->next;
        Liberar_Pagina(del_node);
    }

}


/**
* É usado para Imprimir os Chaves numa Pagina Dada
*/
void imprimir_Pagina(Btree *btree, Pagina * node) {

	int i = 0;

	printf(" { ");
	while(i < node->num) {
		printf(" (%d)", node->chaves[i]);
		i++;
	}
	printf("}");
}

/**
* Imprimir a Arvore B
*/
void Imprimir_SubArvore(Btree *btree,Pagina * node) {

	int i = 0;
	int nivel_atual;

	Pagina * head, * tail;
	Pagina * child;

	nivel_atual = node->nivel;
	head = node;
	tail = node;

	while(true) {
		if(head == NULL) {
			break;
		}
		if (head->nivel < nivel_atual) {
			nivel_atual = head->nivel;
			printf("\n");
		}
        imprimir_Pagina(btree,head);

		if(head->folha == false) {
			for(i = 0 ; i < head->num + 1; i++) {
				child = head->filhos[i];
				tail->next = child;
				tail = child;
				child->next = NULL;
			}
		}
		head = head->next;
	}
	printf("\n");
}
