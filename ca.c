#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
struct lista{
	char info;
	struct lista *prox;
};
struct pilhaop{
	lst *prim;
};
struct pilhareais{
	float vet[20];
	int n;
};
struct calculadora{
	po *operadores;
	pf *reais;
};
po *criapo(){
	po *p=(po*)malloc(sizeof(po));
	p->prim=NULL;
	return p;
}
pf *pfcria(){
	pf *p=(pf*)malloc(sizeof(pf));
	p->n=-1;
	p->vet[p->n]=NULL;
	return p;
}
ca *cacria(){
	ca *c=(ca*)malloc(sizeof(ca));
	c->operadores=criapo();
	c->reais=pfcria();
	return c;
}
void popush(po *p,char c){
	if(c=='*'||c=='+'||c=='-'||c=='/'){
	lst *l;	l=(lst*)malloc(sizeof(lst));
	if(p->prim==NULL){
		l->info=c;
		l->prox=NULL;
		p->prim=l;
	}else{
		l->info=c;
		l->prox=p->prim;
		p->prim=l;
	}
  }else{
  	printf("caracter invalido\n");
  }
}
char popop(po *p){
	if(p->prim==NULL){
		printf("sem dados\n");return 0;
	}else{
	char c;lst *l;
	l=(lst*)malloc(sizeof(lst));
	 if(p->prim->prox==NULL){
		c=p->prim->info;
		p->prim=NULL;
		return c;
	}else{
		c=p->prim->info;
		l=p->prim->prox;
		p->prim=l;
		return c;
	}
  }
}
void poimp(po *p){
	if(p->prim!=NULL){
	lst *i;
	printf("Pilha de operandos:\n");
	for(i=p->prim;i!=NULL;i=i->prox){
		printf("%c \t",i->info);
	}printf("\n");}
}
void polibera(po *p){
	lst *a;
	while(p->prim!=NULL){
		a=p->prim->prox;
		free(p->prim);
		p->prim=a;
	}
}
void pfpush(pf *p,float v){
		if(p->n<19){
		p->n++;
		p->vet[p->n]=v;
	}else{
		printf("nao ha mais espaco\n");
	}
}
float pfpop(pf *p){
	float v;
	if(p->n>=0){
		v=p->vet[p->n];
		p->n--;return v;
	}else{
		printf("nao ha dados\n");return NULL;
	}
}
void pfimp(pf *p){
	if(p->n>-1){
	int i=p->n;
	printf("Pilha de reais:\n");
	while(i!=-1){
		printf("%.2f \t",p->vet[i]);i--;
	}printf("\n");
}
}
void pflibera(pf *p){
	while(p->n!=-1){
		p->vet[p->n];p->n--;
	}
}
void caopush(ca *c,char a){
		lst *l=(lst*)malloc(sizeof(lst));
		if(c->operadores->prim==NULL){
			l->info=a;l->prox=NULL;
			c->operadores->prim=l;
	}else{
		l->info=a;l->prox=c->operadores->prim;
		c->operadores->prim=l;
		printf("aqu\n");
	}
}
void cafpush(ca *c,float v){
		c->reais->n++;
		c->reais->vet[c->reais->n]=v;
}
void caimp(ca *c){
	if(c->operadores->prim!=NULL||c->reais->n>-1){
		printf("Pilha calculadora:\n");
		if(c->operadores->prim!=NULL){
			printf("Operadores:\n");
			lst *l;
			for(l=c->operadores->prim;l!=NULL;l=l->prox){
				printf("%c \t",l->info);
			}printf("\n");
		}	printf("Valores: \n");
			int i=c->reais->n;
			while(i!=-1){
				printf("%.2f \t",c->reais->vet[i]);i--;
			}printf("\n");
	}printf("\n");
}
void calculadora(ca *c){
	if(c->operadores->prim!=NULL||c->reais->n>-1){
		char a=popop(c->operadores);
		float i,j,k;int val=0;
		if(a=='-'){
			i=pfpop(c->reais);	j=pfpop(c->reais);
			k=i-j;pfpush(c->reais,k);
			printf("Resultado: %.2f\n",k);
		}else if(a=='+'){
			i=pfpop(c->reais);	j=pfpop(c->reais);
			k=i+j;pfpush(c->reais,k);
			printf("Resultado: %.2f\n",k);
		}else if(a=='*'){
			i=pfpop(c->reais);	j=pfpop(c->reais);
			k=i*j;pfpush(c->reais,k);
			printf("Resultado: %.2f\n",k);
		}else if(a=='/'){
			i=pfpop(c->reais);	j=pfpop(c->reais);
			k=i/j;pfpush(c->reais,k);
			printf("Resultado: %.2f\n",k);
		}
	}else{
		printf("nao ha dados suficientes\n");
	}
}
void pcpush(pf *f,ca *c){
	float v;
	v=c->reais->vet[c->reais->n];c->reais->n--;
	pfpush(f,v);
}
int vazia(po *p){
	if(p->prim!=NULL)return 1;
	else return 0;
}
int tamanho(pf *f){
	int i;
	for(i=0;i<=f->n;i++){
	}return i;
}
int cteste(ca *c){
	int i;
	for(i=0;i<=c->reais->n;i++){
	}return i;
}
