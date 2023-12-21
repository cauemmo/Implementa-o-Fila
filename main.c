#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
//Cauê Mendonça Magela do Ó
//rgm : 43558

struct Fila{
    int valor;
    struct Fila *prox;
};

void Inserir(int x, struct Fila **ptr){
    struct Fila *pt = malloc(sizeof(struct Fila));
    pt->valor = x;
    pt->prox = NULL;
    *ptr = pt;
}

int main() {
    char string[50];
    int valor, resp, width, height, textwidth, textheight;
    struct Fila *inicio = NULL;
    struct Fila *fim = NULL;
    struct Fila *pt = NULL;
    struct Fila *desalocar = NULL;
    gfx_init(1280, 720, "Lista simplesmente encadeada");
    gfx_set_color(255, 255, 255);
    do{
        printf("1-insercao\n2-remocao\n3-sair\n");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                printf("Informe o numero que sera inserido\n");
                scanf("%d", &valor);
                Inserir(valor, &pt);
                if(fim != NULL){
                    fim->prox = pt;
                }else{
                    inicio = pt;
                }
                fim = pt;
                break;
            case 2:
                if(inicio != NULL){
                    pt = inicio;
                    inicio = inicio->prox;
                    if(inicio == NULL){
                        fim = NULL;
                    }
                    printf("O valor retirado foi = %d\n", pt->valor);
                    free(pt);
                }else{
                    printf("A fila já está vazia\n");
                }
                break;
        }
        gfx_clear();
        width = 0;
        height = 0;
        pt = inicio;
        sprintf(string, "inicio ");
        gfx_get_text_size(string, &textwidth, &textheight);
        gfx_text(width, height, string);
    	width += textwidth;
        while (pt != NULL){
            if(pt->prox != NULL){
    	        sprintf(string, "%d -> ", pt->valor);
    	    }else{
    	        sprintf(string, "%d ", pt->valor);
    	    }
    	    gfx_get_text_size(string, &textwidth, &textheight);
    	    if(width+textwidth <= 1280){
    	        gfx_text(width, height, string);
    	        width += textwidth;
    	    }else{
    	        height += textheight;
    	        gfx_text(0, height, string);
    	        width = textwidth;
    	    }
            pt = pt->prox;
        }
        sprintf(string, " final");
        gfx_get_text_size(string, &textwidth, &textheight);
        gfx_text(width, height, string);
    	width += textwidth;
    	gfx_paint();
    } while (resp != 3);
    pt = inicio;
    while (pt != NULL){
        desalocar = pt;
        pt = pt->prox;
        free(desalocar);
    }
    gfx_quit();
    return 0;
}
