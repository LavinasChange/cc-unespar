/*
 * Atividade061.cpp
 *
 *  Created on: 5 de out de 2017
 *      Author: henrique.silva
 */
/*

#include<windows.h>
#include<gl\gl.h>
#include<gl\glu.h>
#include<gl\glut.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<math.h>

using namespace std;

class Pontos{				// declara��o da classe Ponto
	private:
	int x;
	int y;

	public:
	Pontos(int posicaoX, int posicaoY){
		this->x = posicaoX;
		this->y = posicaoY;
	}

	int getX(){
		return this->x;
	}

	int getY(){
		return this->y;
	}
};

void atualizarArquivo();
void funcaoTeclado(unsigned char tecla, int x, int y);
void funcaoMouse(int botao, int estado, int x, int y);
void funcaoSetas(int tecla, int x, int y);
float calcularDistancia(Pontos p1, int x, int y);
int pontoMaisProx(int x, int y);
void desenharExcl();
void init(void);
void display(void);

int main(int argc, char **argv) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,200);
glutCreateWindow("Atividade 1 de Computa��o Gr�fica - Bruno Noleto");
glutMouseFunc(funcaoMouse);
glutKeyboardFunc(funcaoTeclado);
glutSpecialFunc(funcaoSetas);
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

struct Deletado{		// declara��o da struct Deletado, que servir� apenas para armazenar valores para serem apresentados na tela
	int delX;
	int delY;
	int clickX;
	int clickY;
	boolean mostrar = false;
};

Deletado del;
fstream arquivo;
string textoArquivo;

vector<Pontos> listaPontos;

void atualizarArquivo(){		// fun��o de atualizar a stream que poder� ser salva como arquivo
	textoArquivo.clear();
	for(unsigned int i = 0; i< listaPontos.size(); i++){
		textoArquivo.append(to_string(listaPontos.at(i).getX()));
		textoArquivo.append(" ");
		textoArquivo.append(to_string(listaPontos.at(i).getY()));
		if(i != listaPontos.size()-1){
			textoArquivo.append("\n");
		}
	}
}

void funcaoTeclado(unsigned char tecla, int x, int y){

	string coordenada;
	 switch(tecla){
	 	 case 'e' :
	 		 glScalef(1.1,1.1,1);
	 		 break;
	 	 case 'E' :
	 		 glScalef(0.9,0.9,1);
	 		 break;
	 	 case 'r' :
			 glRotatef(1, 0, 0, 1);
			 break;
	 	 case 'R' :
	 		 glRotatef(-1, 0, 0, 1);
	 		 break;
	 	 case 's' :			// a��o da tecla S para salvar os pontos em arquivo
	 		 if(!arquivo.is_open()){
	 			 arquivo.open("saida.txt", ios::out);
	 		 }
	 		 arquivo << textoArquivo;
	 		 cout << "Arquivo de sa�da gerado!" << endl;
	 		 arquivo.close();
	 		 break;
	 	 case 'o' :			// a��es da tecla O para abrir e importar os pontos indicados no arquivo saida.txt
	 		 arquivo.open("saida.txt", ios::in);
	 		 listaPontos.clear();		// limpar� os pontos da tela
	 		 textoArquivo.clear();		// limpar� a stream textoArquivo pro caso de alterar a imagem importada e salvar posteriormente
	 		 string s((std::istreambuf_iterator<char>(arquivo)), std::istreambuf_iterator<char>());	// string auxiliar para guardar o conte�do do arquivo
	 		 textoArquivo = s;
	 		 arquivo.close();

	 		 int numVariavel = 0;	// contador do n�mero de vari�veis para cada linha
	 		 int coordX, coordY;	// coordenadas que ser�o extra�das no decorrer do la�o
	 		 for(unsigned int i = 0; i< textoArquivo.length(); i++){	// la�o que ir� verificar cada caractere at� o �ltimo item da string extra�da
	 			if(isdigit(textoArquivo.at(i))){
	 				coordenada+=textoArquivo.at(i);
	 			}
	 			else if(coordenada.length() != 0){
	 				if(numVariavel == 0){
	 					coordX = stoi(coordenada); // converter� a string para inteiro
	 					numVariavel++;
	 					//cout << coordenada << endl;
	 				}
	 				else if(numVariavel == 1){		// criar� um ponto na tela a cada 2 vari�veis (x,y)
	 					coordY = stoi(coordenada);
	 					listaPontos.push_back(Pontos(coordX,coordY));
	 					cout << "O ponto (" << coordX << "," << coordY << ") foi criado!" << endl;
	 					numVariavel = 0;
	 					//cout << coordenada << endl;
	 				}
	 				coordenada.clear();
	 			}
	 		 }
	 		 atualizarArquivo();
	 		 break;
	 }
	 glutPostRedisplay();
}

void funcaoSetas(int tecla, int x, int y){
	switch(tecla) {
		case GLUT_KEY_UP :
			glTranslatef(0,-1,0);
			break;
		case GLUT_KEY_DOWN :
			glTranslatef(0,1,0);
			break;
		case GLUT_KEY_LEFT :
			glTranslatef(-1,0,0);
			break;
		case GLUT_KEY_RIGHT :
			glTranslatef(1,0,0);
			break;
	}
	glutPostRedisplay();
}

void funcaoMouse(int botao, int estado, int x, int y){
	if (botao == GLUT_LEFT_BUTTON){
	         if (estado == GLUT_DOWN) {
	        	 listaPontos.push_back(Pontos(x,y));			// ser� instanciado um objeto do tipo Ponto, e ser� armazenado na �ltima posi��o do vetor
	        	 atualizarArquivo();
	        	 cout << "O ponto (" << x << "," << y << ") foi criado!" << endl;
	        	 glutPostRedisplay();
	         }
	}
	if(botao == GLUT_RIGHT_BUTTON){
        if (estado == GLUT_DOWN && listaPontos.size() > 0) {

        	del.delX = listaPontos.at(pontoMaisProx(x,y)).getX();		// essas instru��es armazenam os dados deletados na struct "del",
        	del.delY = listaPontos.at(pontoMaisProx(x,y)).getY();		// para demonstrar tanto no console como na tela, a posi��o em que
        	del.clickX = x;											// o mouse foi clicado, e onde estava o ponto que foi deletado
        	del.clickY = y;
        	float distancia = calcularDistancia(listaPontos.at(pontoMaisProx(x, y)), x,y);

        	listaPontos.erase(listaPontos.begin()+pontoMaisProx(x, y));		// o ponto ser� deletado neste momento, na posi��o retornada na fun��o pontoMaisProx
        	atualizarArquivo();
        	cout << "O ponto (" << del.delX << "," << del.delY << ") foi deletado! (Dist�ncia: " << distancia <<")" << endl;

        	del.mostrar = true;
       	 glutPostRedisplay();
        }
	}
}

float calcularDistancia(Pontos p1, int x, int y){	// f�rmula matem�tica para calcular a dist�ncia entre dois pontos
	float xA = (float)p1.getX();
	float xB = (float)x;
	float yA = (float)p1.getY();
	float yB = (float)y;

	return sqrt(pow((xB-xA),2)+pow((yB-yA),2));
}

int pontoMaisProx(int x, int y){ // retornar� o �ndice do ponto mais pr�ximo ao clique
	unsigned int i;
	float menorDistancia;
	int indiceMenorDistancia;

	for(i = 0; i< listaPontos.size(); i++){		// o la�o ir� comparar as dist�ncias entre cada ponto do vetor e a posi��o clicada
		if(i==0){				// a��o a ser realizada caso tenha apenas 1 ponto declarado no vetor
			menorDistancia = calcularDistancia(listaPontos.at(i), x, y);
			indiceMenorDistancia = i;
		}
		else{					// a��o a ser realizada caso tenha 2 ou mais pontos declarados no vetor
			if(calcularDistancia(listaPontos.at(i), x, y) < menorDistancia){
				menorDistancia = calcularDistancia(listaPontos.at(i), x, y);
				indiceMenorDistancia = i;
			}
		}
	}

	return indiceMenorDistancia;
}

void desenharExcl(){
	glBegin(GL_LINES);
			glVertex2f(del.delX-3, del.delY-3);						// desenhar� 2 linhas cruzadas, formando o "X"
			glVertex2f(del.delX+3, del.delY+3);
	glEnd();
	glBegin(GL_LINES);
			glVertex2f(del.delX+3, del.delY-3);
			glVertex2f(del.delX-3, del.delY+3);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
			glVertex2f((float)del.clickX, (float)del.clickY);		// mostrar� a posi��o em que foi clicado com o mouse
	glEnd();
}

void init(void) {
glClearColor(0.0f, 0.0f, 0.0f ,0.0f);
glLineWidth(1.0);
glPointSize(3);
gluOrtho2D(0, 500, 500, 0);

}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    for(unsigned int i = 0; i< listaPontos.size(); i++){
    	if(i> 0){										// desenhar� a linha entre 2 pontos, respeitando a condi��o do vetor possuir pelo menos tamanho 2
    		glBegin(GL_LINES);
    		    		glVertex2f((float)listaPontos.at(i-1).getX(), (float)listaPontos.at(i-1).getY());
    		    		glVertex2f((float)listaPontos.at(i).getX(), (float)listaPontos.at(i).getY());
    		glEnd();

    	}
    	glBegin(GL_POINTS);
    	    		    glVertex2f((float)listaPontos.at(i).getX(), (float)listaPontos.at(i).getY());		// mostrar� cada ponto na tela
    	glEnd();
    }

    if (del.mostrar == true){			// instru��o para mostrar o X bonitinho na tela e a posi��o clicada, ap�s excluir o ponto
    	desenharExcl();
		del.mostrar = false;
    }
    glutSwapBuffers();
}

*/

