#include<math.h> //Operações matemáticas
#include<stdio.h> //Inclui as funções entradas e saídas do programa
#include<windows.h> //Inclui as bibliotecas gráficas

//Define os métodos usados
int setX(); // Transladar eixo X em (x + 118)
int setY(); // Transladar eixo Y em (34 - y)
void irParaXY(); // Define a posição do cursor
int calculoDDA(); // Calcular Algoritmo de DDA e imprime a reta
void retaDDA(void); // Insere a coordenadas X e Y e chama as outras funções referentes
void poligonoDDA(void);  // Insere a coordenadas X e Y e chama as outras funções referentes
void planoCartesiano(); // Imprime o Plano Cartesiano
void calculoBresenham(); // Calcular Algoritmo de Bresenham e imprime a reta
void retaBresenham(void); // Insere a coordenadas X e Y e chama as outras funções referentes
int ExibirOpcoesInicial(); // Exibe menu principal do programa
void retornaDesafio(void);  // Repete o desafio que foi executado, usa ponteiros 
void circuloPitagoras(void); // Insere a coordenadas Xc, Yc e Raio e chama as outras funções referentes
void circuloBresenham(void); // Insere a coordenadas Xc, Yc e Raio e chama as outras funções referentes
int ExibirOpcoesFinalCerta(); // Mostra as opções depois da impressão após da função
void poligonoBresenham(void); // Insere a coordenadas X e Y e chama as outras funções referentes
int ExibirOpcoesFinalErrada(); // Se a pessoa escolheu um número inválido, aparece essa condição
void calculoCirculoBresenham(); // Calcula com os Xc, Yc e Raio inseridos
void calculosCirculoPitagoras(); // Calcula com os Xc, Yc e Raio inseridos
void circuloCoordenadasPolares(void); // Insere a coordenadas Xc, Yc e Raio e chama as outras funções referentes
void calculoCirculoCoordenadasPolares(); // Calcula com os Xc, Yc e Raio inseridos
void imprimindoValoresRetaBresenham();// Imprime todos os valores relacionados a RetaBresenham
void imprimindoValoresRetaDDA();// Imprime todos os valores relacionados a RetaDDA

/*
----------------------------------//----------------------------------

							IMPORTANTE
							
	PARA MELHOR VISUALIZAÇÃO DO PLANO CARTESIANO:
		Abrir console 
		Clicar com botao direito na barra superior da janela
		Clicar em Propriedades
		Clicar em Fonte
		Definir a fonte no tamanho "16" e fonte "Consolas" 


----------------------------------//----------------------------------
*/


int main() {
	ExibirOpcoesInicial(); // Menu das opções
}

//Método que imprime as opções iniciais
int ExibirOpcoesInicial() {
	int opcao;
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO", 181, 128, 199);
	printf("\n ---------------------------------------------");
	printf("\n\n Escolha o n%cmero referente ao desafio desejado:\n", 163);
	printf("\n (0) - Sair");
	printf("\n (1) - Imprime uma reta (Algoritmo DDA)");
	printf("\n (2) - Imprime uma reta (Algoritmo de Bresenham)");
	printf("\n (3) - Imprime polilinhas formando um pol%cgono (Algoritmo DDA)", 161);
	printf("\n (4) - Imprime polilinhas formando um pol%cgono (Algoritmo de Bresenham)", 161);
	printf("\n (5) - Imprime o tra%cado de um c%crculo (Teorema de Pit%cgoras)", 135, 161, 160);
	printf("\n (6) - Imprime o tra%cado de um c%crculo (Sistemas de coordenadas polares)", 135, 161);
	printf("\n (7) - Imprime o tra%cado de um c%crculo (Algoritmo de Bresenham)", 135, 161);
	printf("\n\n Op%c%co escolhida: ", 135, 198);
	scanf("%d", &opcao);
	switch (opcao) {
	case 0:
		exit(0);
	case 1:
		retaDDA();
	case 2:
		retaBresenham();
	case 3:
		poligonoDDA();
	case 4:
		poligonoBresenham();
	case 5:
		circuloPitagoras();
	case 6:
		circuloCoordenadasPolares();
	case 7:
		circuloBresenham();
	default:
		return ExibirOpcoesFinalErrada();
	}
}

//Método que imprime a mensagem de opção correta
int ExibirOpcoesFinalCerta(void (*ponteiroFuncao)()) { // Função ponteiro para retornar para o mesmo desafio
	int opcao;
	printf("\n -------------------------");
	printf("\n O que deseja fazer agora?\n");
	printf("\n (0) - Sair");
	printf("\n (1) - Repetir desafio atual");
	printf("\n (2) - Escolher novo desafio");
	printf("\n\n Op%c%co escolhida: ", 135, 198);
	scanf("%d", &opcao);
	switch (opcao) {
	case 0:
		exit(0);
	case 1:
		system("cls");
		(*ponteiroFuncao)();
	case 2:
		system("cls");
		ExibirOpcoesInicial();
	default:
		system("cls");
		ExibirOpcoesFinalErrada();
	}
}

//Método que imprime a mensagem de opção inválida
int ExibirOpcoesFinalErrada() {
	int opcao;
	system("cls");
	printf("\n Voc%c digitou uma op%c%co inv%clida! Tente novamente.", 136, 135, 198, 160);
	printf("\n -------------------------------------------------");
	printf("\n\n O que deseja fazer agora?\n");
	printf("\n (0) - Sair");
	printf("\n (1) - Escolher desafio");
	printf("\n\n Op%c%co escolhida: ", 135, 198);
	scanf("%d", &opcao);
	switch (opcao) {
	case 0:
		exit(0);
	case 1:
		system("cls"); // Limpa a tela na saída do comando
		ExibirOpcoesInicial();
	default:
		system("cls");
		ExibirOpcoesFinalErrada();
	}
}

//Método que faz o apontamento das coordenadas X e Y
void irParaXY(int x, int y) {
	COORD coord;
	coord.X = (short) x;
	coord.Y = (short) y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Método que imprime o plano cartesiano na tela
void planoCartesiano(void) {
	int vertical, horizontal;
	for (vertical = 14; vertical < 55 ; vertical++) {//Reta que separa o plano na vertical
		irParaXY(118, vertical);
		printf("|");
	}
	for (horizontal = 18; horizontal < 219; horizontal++) {//Reta que separa o plano na horizontal
		irParaXY(horizontal, 34);
		printf("-");
	}
	irParaXY(118, 34);
	printf("X");//Ponto central
}

//Desloca X em 118 + X
int setX(int x) { 
	return (x + 118); 
}

//Desloca Y em 34- Y
int setY(int y) {
	return (34 - y);
}

//Método que realiza as contas relacionadas ao DDA e imprime Reta
int calculoDDA(int codXI, int codXF, int codYI, int codYF){
	int deltaX, deltaY, auxX, auxY;
	float incX, incY, compX, compY, step;
	deltaX = codXF - codXI;//Início do algoritmo DDA
	deltaY = codYF - codYI;
	auxX = deltaX;
	auxY = deltaY;
	//Teste de valor absoluto
	if (auxX < 0) {// Se delta X der menor que 0, multiplica-se por -1
		auxX *= -1; 
	}
	if (auxY < 0) { // Se delta Y der menor que 0, multiplica-se por -1
		auxY *= -1;
	}
	if (auxX > auxY) {
		step = auxX;// Coloca a váriavel Step = |DeltaX|
	} else {
		step = auxY;// Coloca a váriavel Step = |DeltaY|
	}
	incX = (deltaX / step);// Define o incremento em X
	incY = (deltaY / step);// Define o incremento em Y
	
	compX = (codXI); // Váriavel que começa em XI e será incrementada até XF;
	compY = (codYI); // Váriavel que começa em YI e será incrementada até YF;
	
	while ((codXF != compX) && (codYF != compY)) { // Acrescenta com os valores de Xinc e Yinc até chegar o XF e YF
		irParaXY(setX(compX), setY(compY));
		printf("%c", 219); // 219 --> Quadrado
		compX += incX; // incrementa compX com a váriavel incX(DeltaX/Step);
		compY += incY; // incrementa compY com a váriavel incY(DeltaY/Step);
	}
	
	/*
	Como o algoritmo acima não funcionava para casos onde existia valores iniciais = finais, ou seja:
	
		YF = YI OU XF = XI
		
	Definimos 2 condições para esse caso, onde o incremento só acontece quando:
		
		YF != YI (somente incrementa em Y) OU XF != XI (somente incrementa em X)
	
	*/
	if (codXF == codXI) {
		while (codYF != compY) {
			irParaXY(setX(codXF), setY(compY));
			printf("%c", 219); // 219 --> Quadrado
			compY += incY;	//incrementa a compY com a váriavel incY(DeltaY/Step);
		}
	} else if (codYF == codYI) {
		while (codXF != compX) {
			irParaXY(setX(compX), setY(codYF));
			printf("%c", 219);
			compX += incX;	//incrementa a compX com a váriavel incX(DeltaX/Step);
		}
	}
	irParaXY(setX(codXI), setY(codYI));//Identificando os pontos iniciais e finais
	printf("%c", 219);
	irParaXY(setX(codXF), setY(codYF));
	printf("%c", 219);
	irParaXY(0, 54);
}

//Método que realiza as contas relacionadas ao Bresenham e imprime Reta
void calculoBresenham(int codXI, int codXF, int codYI, int codYF){
	int  deltaX, deltaY, pontoP, incY, incX, incrementoP1y, incrementoP2y, incrementoP1x, incrementoP2x;
	deltaY = (codYF - codYI);//Define DeltaY sendo (YF - YI)
	deltaX = (codXF - codXI);// Define DeltaX sendo (XF - XI)
	
	/*
	 Quando qualquer um dos deltas era menor que 1:
	 	O incremento era definido como -1;
		O delta era multiplicado por -1, para que pudesse ficar positivo. 
	*/
	if (deltaY < 0){
		incY = -1;
		deltaY *= -1;
	} else {// Caso contrário, seguiamos com o incremento 1
		incY = 1;
	}
	if (deltaX < 0) {
		incX = -1;
		deltaX *= -1;
	} else {
		incX = 1;
	}
	
	pontoP = 2 * deltaY - deltaX;// Primeiro ponto P no algorítmo de Bresenham
	
	/*
	
	Fazendo o algoritmo original, existia um problema quando o deltaY era maior que o deltaX
	Isso acontecia, porque o algoritmo foi designado para lidar com retas com coeficiente angular positivo
	Logo, percebemos que caso invertessemos, nas fórmulas de incremento de P, os valores de deltaX e deltaY quando existisse um deltaY maior que deltaX, funcionaria
	
	*/
	
	// Caso Delta X > Delta Y
	incrementoP1y =  (2 * deltaY);// Definindo o valor que ia ser somado a P ( Se P <= 0 )
	incrementoP2y =  (2 * deltaY) - (2 * deltaX);// Definindo o valor que ia ser somado a P ( Se P > 0 )
	
	// Caso Delta X < Delta Y
	incrementoP1x = (2 * deltaX);// Definindo o valor que ia ser somado a P ( Se P <= 0 ) 
	incrementoP2x = (2 * deltaX) - (2 * deltaY);// Definindo o valor que ia ser somado a P ( Se P > 0 ) 
	
	irParaXY(setX(codXI), setY(codYI));
	printf("%c", 219);
	if (deltaX > deltaY) {
		while (codXI != codXF) {
			codXI += incX;// Incrementa XI até XF
			if (pontoP <= 0) {
				pontoP += incrementoP1y;  // Incrementa ponto P caso Panterior <= 0
			}
			else {
				codYI += incY; // Incrementa YI até YF
				pontoP += incrementoP2y; // Incrementa ponto P caso Panterior > 0 
			}
			irParaXY(setX(codXI), setY(codYI));
			printf("%c", 219);
		}	
	} else { // Aqui invertemos as fórmulas, para que pudessemos retirar os erros
		pontoP = 2 * deltaX - deltaY;
		while (codYI != codYF) {
			codYI += incY; // Incrementa YI até YF
			if (pontoP <= 0) {
				pontoP += incrementoP1x; // Incrementa ponto P caso Panterior <= 0
			}
			else {
				codXI += incX;// Incrementa XI até XF
				pontoP += incrementoP2x; // Incrementa ponto P caso Panterior > 0 
			}
			irParaXY(setX(codXI), setY(codYI));
			printf("%c", 219);
		}		
	}	
}

//Método chamado na tela de opções iniciais. Opção 1
void retaDDA(void) {
	int codXI, codYI, codXF, codYF;
	void *ponteiroFuncao; 
	ponteiroFuncao = &retaDDA;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 1) Imprime uma reta (Algoritmo DDA)");
	printf("\n -----------------------------------\n");
	printf("\n Insira a coordenada inicial de X: ");
	scanf("%d", &codXI);
	printf("\n Insira a coordenada inicial de Y: ");
	scanf("%d", &codYI);
	printf("\n Insira a coordenada final de X: ");
	scanf("%d", &codXF);
	printf("\n Insira a coordenada final de Y: ");
	scanf("%d", &codYF);
	planoCartesiano();//Imprime o plano cartesiano para referência
	calculoDDA(codXI, codXF, codYI, codYF);// Faz as contas relacionadas ao DDA	
	imprimindoValoresRetaDDA(codXF, codXI, codYF, codYI); // Chama os códigos da void retaDDA(void) e implementa no "imprimindoValoresRetaDDA"
	ExibirOpcoesFinalCerta(&retaDDA);
}
// Abaixo do Plano Cartesiano, há os cálculos passo a passo impressos, junto com os pontos encontrados
void imprimindoValoresRetaDDA(int XF, int XI, int YF, int YI){
		int deltaX, deltaY, auxX, auxY;
		float Xinc, Yinc, step, comparaX, comparaY;
		deltaX = XF - XI;
		deltaY = YF - YI; 
		printf("\n**************************************** \n");
		printf ("\n Delta X %c: %d - %d = %d ", 130, XF, XI, deltaX);
		printf ("\n Delta Y %c: %d - %d = %d", 130, YF, YI, deltaY);
		printf("\n**************************************** \n");
		auxX = deltaX;
		auxY = deltaY;
		
		
		/*
		Mesma lógica utilizada no cálculoDDA, porém agora com o objetivo de imprimir todos os valores.
		*/
		if (auxX < 0) {
			auxX *= -1; 
		}
		if (auxY < 0) {
			auxY *= -1;
		}
	
		if (auxX > auxY) {
		    step = auxX;
			printf ("\n Step %c = %.1f", 130, step);
		} else {
			step = auxY;
			printf ("\n Step %c = %.1f", 130, step);
		}
		
		Xinc = (deltaX / step);	
		Yinc = (deltaY / step);
		
		printf("\n**************************************** \n");
		printf ("\n Xinc = %.1f", Xinc);
		printf ("\n Yinc = %.1f", Yinc);
		printf("\n**************************************** \n");
		
		printf ("\n Ponto inicial: (%d; %d)", XI, YI);
		
		comparaX = XI;
		comparaY = YI;
		while ((XF != comparaX) && (YF != comparaY)) {
			comparaX += Xinc;
			comparaY += Yinc;
		printf("\n Pontos encontrados: (%.1f; %.1f)", comparaX, comparaY); // Para todos os casos de comparação
		}
		
		if (XF == XI) {
			while (YF != comparaY) {
			comparaY += Yinc;
			printf("\n Pontos encontrados: (%.1f; %.1f)", comparaX, comparaY);
			} 
				} else if (YF == YI) {
			while (XF != comparaX) {
			comparaX += Xinc;
			printf("\n Pontos encontrados: (%.1f; %.1f)", comparaX, comparaY);
			}
		}
		
	}

//Método chamado na tela de opções iniciais. Opção 2
void retaBresenham(void) {
	int codXI, codYI, codXF, codYF;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 2) Imprime uma reta (Algoritmo de Bresenham)");
	printf("\n --------------------------------------------\n");
	printf("\n Insira a coordenada inicial de X: ");
	scanf("%d", &codXI);
	printf("\n Insira a coordenada inicial de Y: ");
	scanf("%d", &codYI);
	printf("\n Insira a coordenada final de X: ");
	scanf("%d", &codXF);
	printf("\n Insira a coordenada final de Y: ");
	scanf("%d", &codYF);
	planoCartesiano();//Imprime um plano cartesiano para referência
	calculoBresenham(codXI, codXF, codYI, codYF);//Método que faz a reta através do algoritmo de Bresenham
	irParaXY(0, 54);
	imprimindoValoresRetaBresenham(codXF, codXI, codYF, codYI);
	ExibirOpcoesFinalCerta(&retaBresenham);
}
// Abaixo do Plano Cartesiano, há os cálculos passo a passo impressos, junto com os pontos encontrados
void imprimindoValoresRetaBresenham(int XF, int XI, int YF, int YI) {
	int deltaX, deltaY, dobraDeltaX, dobraDeltaY, diferencaDeltas, pontoInicial, pontoMenor, pontoMaiorOuIgual, pontoMenorX, pontoMaiorOuIgualX, comparaX, comparaY;
	float Xinc, Yinc;
	
	deltaX = (XF - XI);
	deltaY = (YF - YI); 
	
		
	printf("\n**************************************** \n");
	printf(" \nDelta de X %c: %d - %d = %d ", 130, XF, XI, deltaX);
	printf(" \nDelta de Y %c: %d - %d = %d ", 130, YF, YI, deltaY);
	printf("\n**************************************** \n");
	
	if (deltaY < 0) {
		deltaY *= -1;
		Yinc = -1;
	} else {
		Yinc =1;
	}
	if (deltaX < 0) {
		deltaX *= -1;
		Xinc = -1;
	} else {
		Xinc =1;
	}

	dobraDeltaX = (2*deltaX);
	dobraDeltaY = (2*deltaY);
	
	printf(" \n O m%cdulo de 2*DeltaX %c: %d", 162, 130, dobraDeltaX);
	printf(" \n O m%cdulo de 2*DeltaY %c: %d", 162, 130, dobraDeltaY);
	printf("\n**************************************** \n");
	
	diferencaDeltas = dobraDeltaY - dobraDeltaX;
	printf(" \n |2*DeltaY| - |2*DeltaX| = %d", diferencaDeltas);
	printf("\n**************************************** \n");
	
	pontoInicial = dobraDeltaY - deltaX;
	printf(" \n Ponto Inicial %c: %d", 130, pontoInicial);
	printf("\n**************************************** \n");
	printf ("\n P = %d | X = %d | Y = %d", pontoInicial, XI, YI);
	
	/*
		Mesma lógica utilizada no calculoBresenham, porém agora com o objetivo de imprimir todos os valores.
	*/
	
	//DeltaX > DeltaY
	pontoMenor = (dobraDeltaY); // para Po < 0, p = po + 2deltaY
	pontoMaiorOuIgual = (dobraDeltaY - dobraDeltaX);// para Po >= 0, p = po + 2deltaY - 2deltaX
	
	//DeltaX < DeltaY
	pontoMenorX = (dobraDeltaX); // para Po < 0, p = po + 2deltaY
	pontoMaiorOuIgualX = (dobraDeltaX - dobraDeltaY);// para Po >= 0, p = po + 2deltaY - 2deltaX
	comparaX = XI;
	comparaY = YI;
	
	if (deltaX > deltaY) {
		while (comparaX != XF) {
			comparaX += Xinc;
			if (pontoInicial < 0) {
				pontoInicial += pontoMenor;
					printf ("\n P = %d | X = %d | Y = %d", pontoInicial, comparaX, comparaY);
			} else {
				comparaY += Yinc;
				pontoInicial += pontoMaiorOuIgual;
					printf ("\n P = %d | X = %d | Y = %d", pontoInicial, comparaX, comparaY);
			}
		}
	}else{
		while (comparaY != YF) {
			comparaY += Yinc;
			if (pontoInicial < 0) {
				pontoInicial += pontoMenorX;
					printf ("\n P = %d | X = %d | Y = %d", pontoInicial, comparaX, comparaY);
			}
			else {
				comparaX += Xinc;
				pontoInicial += pontoMaiorOuIgualX;
					printf ("\n P = %d | X = %d | Y = %d", pontoInicial, comparaX, comparaY);
			}
	}
}
}

//Método chamado na tela de opções iniciais. Opção 3
void poligonoDDA(void) {
	int codXI, codYI, codXF, codYF, arestas, xACC, yACC, i;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 3) Imprime polilinhas formando um pol%cgono (Algoritmo DDA)", 161);
	printf("\n ----------------------------------------------------------\n");
	printf("\n Insira o n%cmero de arestas do seu pol%cgono: ", 163, 161);
	scanf("%d", &arestas);
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 3) Imprime polilinhas formando um pol%cgono (Algoritmo DDA)", 161);
	printf("\n ----------------------------------------------------------\n");
	printf("\n Insira a coordenada inicial de X: ");
	scanf("%d", &codXI);
	printf("\n Insira a coordenada inicial de Y: ");
	scanf("%d", &codYI);
	printf("\n Insira a coordenada final de X: ");
	scanf("%d", &codXF);
	printf("\n Insira a coordenada final de Y: ");
	scanf("%d", &codYF);
	planoCartesiano();
	calculoDDA(codXI, codXF, codYI, codYF);
	for(i = 1; i < arestas; i++){	// Enquanto não terminar o numero de arestas, faça uma nova reta
		irParaXY(0, 10);
		printf("                                                   "); // Limpa a linha referente a coordenada final de X
		irParaXY(0, 12);
		printf("                                                   "); // Limpa a linha referente a coordenada final de Y
		xACC = codXF;
		yACC = codYF;
		irParaXY(0, 9);
		printf("\n Insira a coordenada do pr%cximo ponto em X: ", 162);
		scanf("%d", &codXF);
		printf("\n Insira a coordenada do pr%cximo ponto em Y: ", 162);
		scanf("%d", &codYF);
		calculoDDA(xACC, codXF, yACC, codYF);// imprime reta
	}
	irParaXY(0, 54);
	ExibirOpcoesFinalCerta(&poligonoDDA);
}

//Método chamado na tela de opções iniciais. Opção 4
void poligonoBresenham(void) {
	int codXI, codYI, codXF, codYF, arestas, xACC, yACC, i;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 4) Imprime polilinhas formando um pol%cgono (Algoritmo de Bresenham)", 161);
	printf("\n -------------------------------------------------------------------\n");
	printf("\n Insira o n%cmero de arestas do seu pol%cgono: ", 163, 161);
	scanf("%d", &arestas);
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 4) Imprime polilinhas formando um pol%cgono (Algoritmo de Bresenham)", 161);
	printf("\n -------------------------------------------------------------------\n");
	printf("\n Insira a coordenada inicial de X: ");
	scanf("%d", &codXI);
	printf("\n Insira a coordenada inicial de Y: ");
	scanf("%d", &codYI);
	printf("\n Insira a coordenada final de X: ");
	scanf("%d", &codXF);
	printf("\n Insira a coordenada final de Y: ");
	scanf("%d", &codYF);
	planoCartesiano();
	calculoBresenham(codXI,codXF,codYI,codYF);
	for(i = 1; i < arestas; i++){// Enquanto não terminar o numero de arestas, faça uma nova reta
		irParaXY(0, 10);
		printf("                                                   ");// Limpa a linha referente a coordenada final de X
		irParaXY(0, 12);
		printf("                                                   ");// Limpa a linha referente a coordenada final de Y
		xACC = codXF;
		yACC = codYF;
		irParaXY(0, 9);
		printf("\n Insira a coordenada do pr%cximo ponto em X: ", 162);
		scanf("%d", &codXF);
		printf("\n Insira a coordenada do pr%cximo ponto em Y: ", 162);
		scanf("%d", &codYF);
		calculoBresenham(xACC, codXF, yACC, codYF);// imprime reta
	}
	irParaXY(0, 54);
	ExibirOpcoesFinalCerta(&poligonoBresenham);
}

//Método que faz os cálculos para o círculo usando Pitágoras
void calculoCirculoPitagoras(int xc, int yc, int r){
	int x, y, y1, y2, x1, x2;
	irParaXY(setX(2*xc), setY(yc));
	printf("X");
	
	/*
		Todos os circulos dão uma alteração em X, já que o pixel do DOS é retangular. 
		Para resolver o problema, multiplicamos por 2 todos o valores referentes a X;
	*/
	
	for(x = (xc - r); x <= (xc + r); x++){ 
	/*
		Fórmulas referentes ao cálculo do circulo pitagoras:
		
			y = yc +/- sqrt( r^2 ) - ( x - xc )^2	
		
	*/
		y1 = yc + sqrt(pow(r, 2) - pow((x - xc), 2)); 
		y2 = yc - sqrt(pow(r, 2) - pow((x - xc), 2)); 
		irParaXY(setX(2*x), setY(y1));
		printf("%c", -2);
		irParaXY(setX(2*x), setY(y2));
		printf("%c", -2);
	}
	// Para a melhor visualização dos pontos na tela, usamos Y sendo incrementado em 1 e X com incremento baseado nas formulas;
	for(y = (yc - r); y <= (yc + r); y++){
		/*
			Fórmulas referentes ao cálculo do circulo pitagoras:
			
				x = xc +/- sqrt( r^2 ) - ( y - yc )^2
				
		*/
		x1 = xc + sqrt(pow(r, 2) - pow((y - yc), 2));
		x2 = xc - sqrt(pow(r, 2) - pow((y - yc), 2));
		irParaXY(setX(2*x1), setY(y));
		printf("%c", -2);
		irParaXY(setX(2*x2), setY(y));
		printf("%c", -2);
	}
	
}

//Método chamado na tela de opções iniciais. Opção 5
void circuloPitagoras(void) {
	system("cls");
	int xc, yc, r;
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 5) Imprime o tra%cado de um c%crculo (Teorema de Pit%cgoras)", 135, 161, 160);
	printf("\n ---------------------------------------------------------\n");
	printf("\n Insira o X central do c%crculo: ", 161);
	scanf("%d", &xc);
	printf("\n Insira o Y central do c%crculo: ", 161);
	scanf("%d", &yc);
	printf("\n Insira o raio do c%crculo: ", 161);
	scanf("%d", &r);
	planoCartesiano();
	calculoCirculoPitagoras(xc, yc, r);
	irParaXY(0, 54);
	ExibirOpcoesFinalCerta(&circuloPitagoras);	
}

//Método que faz os cálculos para o círculo usando o algoritmo de coordenadas polares
void calculoCirculoCoordenadasPolares(int xc, int yc, int r) {
	int x, y, x1, y1;	
	
	/*
		Todos os circulos dão uma alteração em X, já que o pixel do DOS é retangular. 
		Para resolver o problema, multiplicamos por 2 todos o valores referentes a X;
	*/
	
	irParaXY(setX(2 * xc), setY(yc));
	printf("X");
	double i;
	x1 = 2 * (r + xc); 
	y1 = yc;
	for(i = 0.0; i <= 2 *  M_PI; i += (M_PI / 4)){
		x = (xc) + r * cos(i);//Essa variável foi multiplcado por 2 na linha 431.
		y = yc + r * sin(i);
		irParaXY(setX(2 * x), setY(y));
		printf("%c", 219);
		calculoBresenham(x1,(2 * x), y1, y);
		x1 = (2 * x);
		y1 = y;
	}
}

//Método chamado na tela de opções iniciais. Opção 6
void circuloCoordenadasPolares(void) {
	int xc, yc, r;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 6) Imprime o tra%cado de um c%crculo (Sistemas de coordenadas polares)", 135, 161);
	printf("\n --------------------------------------------------------------------\n");
	printf("\n Insira o X central do c%crculo: ", 161);
	scanf("%d", &xc);
	printf("\n Insira o Y central do c%crculo: ", 161);
	scanf("%d", &yc);
	printf("\n Insira o raio do c%crculo: ", 161);
	scanf("%d", &r);
	planoCartesiano();
	calculoCirculoCoordenadasPolares(xc, yc, r);
	irParaXY(0, 54);
	ExibirOpcoesFinalCerta(&circuloCoordenadasPolares);
}

//Método que faz os cálculos para o círculo usando o algoritmo de Bresenham
void calculoCirculoBresenham(int xc, int yc, int r) {
	int x, y, p, varControle;
	p = 1 - (r + yc);
	y = (r + yc);
	x = xc;
	irParaXY(setX(x), setY(y));
	printf("%c", 219);
	/*
		Como precisavamos de um vetor e o numero de pontos varia dependendo dos valores X e Y, 
		Utilizamos uma variável de controle para definir o tamanho do vetor.
	*/
	while(x < y){
		x++;
		if(p < 0){
			p = p + 2 * x + 1;
		} else {
			y--;
			p = p + 2 * x + 1 - 2 * y;
		}
	}
	varControle = x; // Define o número de pontos que serão utilizados para os X e Y determinados
	int vetorX[varControle];
	int vetorY[varControle];
	// Começam aqui os cálculos referentes ao circulo Bresenham
	int i = 0;
	p = 1 - (r + yc); 
	y = (r + yc);
	x = xc;
	
	/*
		Todos os circulos dão uma alteração em X, já que o pixel do DOS é retangular. 
		Para resolver o problema, multiplicamos por 2 todos o valores referentes a X;
	*/
	
	// octante 2:
	while(x < y){
		x++;
		if(p < 0) {
			p = p + 2 * x + 1;
		} else {
			y--;
			p = p + 2 * x + 1 - 2 * y;
		}
		vetorX[i] = y;
		vetorY[i] = x;
		i++;
		irParaXY(setX(2*x), setY(y));
		printf("%c", 219);
	}	

	for(i = 0; i < varControle; i++) {
		irParaXY(setX(2*vetorX[i]), setY(vetorY[i]));	  //octante 1
		printf("%c", 219);
		
		irParaXY(setX( -2*vetorY[i]), setY(vetorX[i]));	  //octante 3
		printf("%c", 219);
		
		irParaXY(setX( -2*vetorX[i]), setY(vetorY[i]));	  //octante 4
		printf("%c", 219);
		
		irParaXY(setX( -2*vetorX[i]), setY( - vetorY[i]));     //octante 5
		printf("%c", 219);
		
		irParaXY(setX( -2*vetorY[i]), setY( - vetorX[i]));     //octante 6
		printf("%c", 219);
		
		irParaXY(setX( 2*vetorY[i]), setY( - vetorX[i]));	  //octante 7
		printf("%c", 219);
		
		irParaXY(setX( 2*vetorX[i]), setY( - vetorY[i]));	  //octante 8
		printf("%c", 219);
	}
}

//Método chamado na tela de opções iniciais. Opção 7
void circuloBresenham(void) {
	int xc, yc, r;
	system("cls");
	printf("\n TRABALHO PR%cTICO - ALGORITMOS DE RASTERIZA%c%CO\n", 181, 128, 199);
	printf("\n 7) Imprime o tra%cado de um c%crculo (Algoritmo de Bresenham)", 135, 161);
	printf("\n -----------------------------------------------------------\n");
	printf("\n Insira o raio do c%crculo: ", 161);
	scanf("%d", &r);
	planoCartesiano();
	calculoCirculoBresenham(0, 0, r);
	irParaXY(0, 54);
	ExibirOpcoesFinalCerta(&circuloBresenham);
}

