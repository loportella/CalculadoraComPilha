#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
int main(int argc, char** argv) {
	int o,r;char c;float v;
	ca *cal;
	po *p;p=criapo();pf *f;f=pfcria();
	cal=cacria();
	do{
		printf("1-Adicionar valor real\n2-Colocar operando(+,-,*,/)\n3-Calculcular\n4-Mostrar pilhas\n0-Fechar \t ");
		scanf("%d",&o);
		switch(o){
		case 1:printf("valor: ");scanf("%f",&v);
		pfpush(f,v);break;
		case 2: printf("letra ");fflush(stdin);
			c=getchar();popush(p,c);break;
		case 3:	
		if(tamanho(f)>1&&vazia(p)!=0){	
		cafpush(cal,pfpop(f));
		caopush(cal,popop(p));
		cafpush(cal,pfpop(f));
		r=cteste(cal);
		calculadora(cal);
		if(r>cteste(cal))pcpush(f,cal);	
}else printf("Coloque dois val reais ou um operador\n");break;
		case 4:	pfimp(f);poimp(p);caimp(cal);break;
		default: printf("Digite uma opcao valida\n");break;
	}
	}while(o!=0);
	polibera(p);pflibera(f);
	
	system("pause");
	return 0;
}
