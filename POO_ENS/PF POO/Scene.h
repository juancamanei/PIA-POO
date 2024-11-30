#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "water2.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include "EspirituA.h"
#include"FlorA.h"
#include "RanaA.h"
#include "tornadoA.h"
#include "LOBO.h"
#define BILLSIZE 50


//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO
//vamos anotar lo que se te puede olvidar mamahuevo
//linea 804,815 estan nuestros void de morir por si los dejas apagados no se te olvide


//tratemos de pensar mijo
//si talar>=5 entonces puedes terminar el juego
//actualizacion 30/11/2024 me molesto un huevo el tener que recolectar 5 asi que quedo en tres 

class Scene : public Camera
{
public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation;
	float hf = 0;
	int hi = 0;
	float hf1 = 0;
	int hi1 = 0;
	int ovejascontar = 0;//aun no lo uso

	bool si = false;
	bool apagarcolision=false;//no puedo, si pudimos pero algo paso
	bool reinicio=false;


	bool Talar = false;//si
	bool eliminarOveja1 = false;//si
	bool eliminarOveja2 = false;//si
	bool eliminarOveja3 = false;//si

	bool Prende=true;//aun no lo uso es para la casa

	bool neblina=false;//si
	bool eliminarBolsa = false;//si
	bool instruccion=false;//si
	
	int i = 0;
	float m = 0;
	int a = 0;
	float b = 0;
	int c = 0;

	GLfloat AmbMat[4] = { 255, 255, 220, 1 };
	GLfloat color[4] = {0.149f,0.067f,0.225f,0.04f};
	GLfloat color2[4] = { 0.195f,0.214f,0.217f,0.085f };
	SkyDome* skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//PRUEBA.jpg");
	Terrain* terrain, * terrain2;
	Water* lago, * lago2;
	Fog* niebla;
	Fog* nieblaaMBIENTAL;

	
	EDXFramework::Model* LOBO;
	EDXFramework::Model* ROCA;
	EDXFramework::Model* TARIMA;
	EDXFramework::Model* OVEJA1;
	EDXFramework::Model* OVEJA2;
	EDXFramework::Model* OVEJA3;
	EDXFramework::Model* GRASS;
	EDXFramework::Model* ARBOL;

	//ESTRUCTURA TRISTE PERO MI MEJOR INTENTO
	EDXFramework::Model* ESTRUCTURAPEDORRA;
	EDXFramework::Model* ESTRUCTURAPEDORRA2;
	EDXFramework::Model* PUENTESILLO;
	EDXFramework::Model* REJA;
	EDXFramework::Model* REJA2;
	//ESTRUCTURA equis


	//cosas de la casa
	EDXFramework::Model* zapatines;
	EDXFramework::Model* cama;
	EDXFramework::Model* Silla;
	EDXFramework::Model* Comida;
	EDXFramework::Model* Mesa;
	EDXFramework::Model* FLECHAS;
	EDXFramework::Model* FLECHAS2;
	//animaciones
	TORN* tornado;
	FlorA* GRAS1;
	FlorA* FLOR2;
	Rana* RANA;
	FlorA* BOLSA;
	EspirituA* ESPIRITU[10];
	Lobo* WOLF[5];

	Colision* rejaC;
	Colision* rejaC2;
	Colision* rejaC3;
	Colision* colision2;//reja mapap
	Colision* colision3;//reja mapa
	Colision* colision4;//reja mapa
	Colision* colision5;//reja mapa
	Colision* colisionPuente;
	Colision* colisiontornado;
	Colision* bolsaColision;
	Colision* PiedraC1;
	Colision* PiedraC2;
	Colision* PiedraC3;
	Colision* PiedraC4;
	Colision* PiedraC5;
	Colision* PiedraC6;
	Colision* PiedraC7;
	Colision* PiedraC8;
	Colision* PiedraC9;
	Colision* PiedraC10;
	Colision* Tunel1;
	Colision* Tunel2;
	Colision* EstructuraColi;
	Colision* EstructuraColi2;
	Colision* Vida;
	Colision* Vida2;
	Colision* Vida3;
	Colision* Privado;//es el de mi cara
	



	Billboard* confeti[5];
	Billboard* lloraelcielo[4];
	Billboard* MenosV0;
	Billboard* MenosV01;
	Billboard* MenosV02;
	Billboard* MenosV;
	Billboard* MenosV2;
	Billboard* MenosV3;
	Billboard* MenosV4;
	Billboard* MenosV5;
	Billboard* game;
	Billboard* Simon;
	Billboard* MayeTriste;
	Billboard* khepasoMaster;
	
	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;
		
		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);
		//-----------------------------------------lluviaaa tus besos son tan frios como la lluvia------------------------------------
		lloraelcielo[0] = new Billboard(hWnd, L"Imagenes//Lluvia//lluvia1.png", 50, 30, 118, 25, 0);
		lloraelcielo[1] = new Billboard(hWnd, L"Imagenes//Lluvia//lluvia2.png", 50, 30, 118, 25, 0);
		lloraelcielo[2] = new Billboard(hWnd, L"Imagenes//Lluvia//lluvia3.png", 50, 30, 118, 25, 0);
		lloraelcielo[3] = new Billboard(hWnd, L"Imagenes//Lluvia//lluvia4.png", 50, 30, 118, 25, 0);

		//--------------------------------bilboard de win------------------------------------
		confeti[0] = new Billboard(hWnd, L"Imagenes//confeti.png//1.png", 10, 10, 118, 35, 0);
		confeti[1] = new Billboard(hWnd, L"Imagenes//confeti.png//2.png", 10, 10, 118, 35, 0);
		confeti[2] = new Billboard(hWnd, L"Imagenes//confeti.png//3.png", 10, 10, 118, 35, 0);
		confeti[3] = new Billboard(hWnd, L"Imagenes//confeti.png//4.png", 10, 10, 118, 35, 0);
		confeti[4] = new Billboard(hWnd, L"Imagenes//confeti.png//5.png", 10, 10, 118, 35, 0);

		//---------------------------------------------bilboards de nomas una imagen---------------------------------------------
		game = new Billboard(hWnd, L"Imagenes//INSTRUCTIVO.jpg", 10, 10, 134, 30, -75);//instruccion
		Simon = new Billboard(hWnd, L"Imagenes//spiderman-si-meme.png", 4, 4, 122, 40, 247);//pa que  cuando obtengas la bolsa
		MayeTriste = new Billboard(hWnd, L"Imagenes//maye_dia_normal.png", 10, 10, 225, 30, -98);//pa que  cuando no obtengas la bolsa no puedas entrar
		khepasoMaster = new Billboard(hWnd, L"Imagenes//que paso master.jpg", 10, 10, 30, 30, 0);//para cuando pierdas


		MenosV02 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 144, 35, 241);//c1 si
		MenosV01 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 112, 35, 216);//c1 si
		MenosV0 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 108, 35, 258);//c1 si
		MenosV = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 78, 35, 270);//c1 si
		MenosV2 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 113, 35, 293);//CC2
		MenosV3 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 129, 35, 277);//C4
		MenosV4 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 139, 35, 205);//C3
		MenosV5 = new Billboard(hWnd, L"Imagenes//menosvida.png", 15, 15, 95, 35, 168);//C5
		//---------------------------------------------------------  colisiones  --------------------------------------------
		
		colision2 = new Colision(5,800, 379, 0, 318);//el del mapa1 rango x atras construccion jala
		colision3 = new Colision(800, 5, 376, 0, 350);//el del mapa2 rango z alado del tornado jala
		colision4 = new Colision(5, 800, -350, 0, -360);//el del mapa3 rango x
		colision5 = new Colision(800, 5, -333, 0, -376);//el del mapa4 rango z--atras del rio jala
		colisiontornado = new Colision(100, 100, 118, 0, 236);//si jala es para que salga la niebla

		Vida = new Colision(15, 15, 108, 0, 259);//jala
		Vida2 = new Colision(15, 15, 112, 0, 216);//
		Vida3 = new Colision(15, 15, 144, 0, 241);//
		PiedraC1 = new Colision(12, 8, 76, 0, 248);//si --a esta le quiero poner un bilboard
		PiedraC2 = new Colision(11, 11, 128, 0, 270);//si
		PiedraC3 = new Colision(11, 11, 129, 0, 277);//si
		PiedraC4 = new Colision(8, 8 , 139, 0, 205);//si
		PiedraC5 = new Colision(8, 8, 95, 0,168);//si
		PiedraC6 = new Colision(8, 8, 121, 0, 184);//si
		PiedraC7 = new Colision(8, 9, 109, 0, 197);//si
		PiedraC8 = new Colision(8, 9, 74, 0, 200);//si
		PiedraC9 = new Colision(8, 9, 14, 0, 234);//si
		PiedraC10 = new Colision(8, 9, 84, 0, 306);//si

		Privado = new Colision(55, 55, 276, 0, -103);//con colision hasta que termine el juego
		EstructuraColi = new Colision(20, 20, 293, 0,-72);
		EstructuraColi2 = new Colision(15, 15, 293, 0, -72);
		Tunel1 = new Colision(1, 18, 294, 0, -99);//-marca error
		Tunel2 = new Colision(1, 18, 284, 0, -99);

		rejaC = new Colision(3, 52, -137,0,97);
		rejaC2 = new Colision(3, 52, -274, 0, 97);
		rejaC3 = new Colision(68, 3, -194, 0, 156);
		//---------------------------------------------------------terrenos base--------------------------------------------
		lago = new Water(hWnd, L"Imagenes//FUCHI.jpg", L"Imagenes//FUCHI.jpg", 512, 512);
		lago2 = new Water(hWnd, L"Imagenes//FUCHI.jpg", L"Imagenes//FUCHI.jpg", 600, 600);
		niebla = new Fog(color, 0.01);
		terrain = new Terrain(hWnd, L"Imagenes//terreno001.bmp", L"Imagenes//LODO_PIEDRA.jpg", L"Imagenes//LODO_PIEDRA.jpg",800,800);
		terrain2 = new Terrain(hWnd, L"Imagenes//terreno_fondo1.bmp", L"Imagenes//PIEDRA_LODO.jpg", L"Imagenes//PIEDRA_LODO.jpg", 800, 800);
		//--------------------------------------------------------- animaciones --------------------------------------------
		GRAS1 = new FlorA(0, 0, 0, 0, 0, "Modelos//pasto//pastin2.obj", "Modelos//pasto//model0.bmp", 1);
		FLOR2 = new FlorA(0, 0, 0, 0, 0, "Modelos//flower//OTRA FLOR.obj", "Modelos//flower//florecillaAmarilla.bmp", 1);
		//ESPIRITU
		ESPIRITU[0] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua01.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[1] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua02.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[2] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua03.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[3] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua04.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[4] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua05.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[5] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua06.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[6] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua07.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[7] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua08.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[8] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua09.obj", "mod//spitiru//espitiru.bmp", 1);
		ESPIRITU[9] = new EspirituA(0, 43, -80, 10, 10, "mod//spitiru//agua10.obj", "mod//spitiru//espitiru.bmp", 1);
		//LOBO
		WOLF[0] = new Lobo(0, 0, 0, 0, 0, "mod//lobote//wolf1.obj", "mod//lobote//wolftext.bmp", 1);
		WOLF[1] = new Lobo(0, 0, 0, 0, 0, "mod//lobote//wolf2.obj", "mod//lobote//wolftext.bmp", 1);
		WOLF[2] = new Lobo(0, 0, 0, 0, 0, "mod//lobote//wolf3.obj", "mod//lobote//wolftext.bmp", 1);
		WOLF[3] = new Lobo(0, 0, 0, 0, 0, "mod//lobote//wolf4.obj", "mod//lobote//wolftext.bmp", 1);
		WOLF[4] = new Lobo(0, 0, 0, 0, 0, "mod//lobote//wolf5.obj", "mod//lobote//wolftext.bmp", 1);
		//RANA Y TORNADO
		RANA = new Rana(10, 10, 0, 0, 25, "Modelos//Rana//rana.obj", "Modelos//Rana//ranita.bmp", 1);
		tornado = new TORN(20, 20, 0, 0, 0, "Modelos//Tornado//TORNADINGI.obj", "Modelos//Tornado//NO.bmp", 1,118,236);
		//BOLSA
		BOLSA = new FlorA(3, 3, 118, 0, 236, "Modelos//BOLSAOV//bolsa.obj", "Modelos//BOLSAOV//TexturaBolsa.bmp", 1);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//--------------------------------------------------------- MODELOS SIN ANIMACIÓN --------------------------------------------
		FLECHAS = new EDXFramework::Model(8, 8, 109, 0, -75, "Modelos//felchas//flechas.obj", "Modelos//felchas//madera1.bmp", 1);
		FLECHAS2 = new EDXFramework::Model(8, 8, 109, 0, -75, "Modelos//felchas//flechas.obj", "Modelos//felchas//cuidado.bmp", 1);

		LOBO = new EDXFramework::Model(0, 0, 0, 0, 0, "mod//lobote//wolf1.obj", "mod//lobote//wolftext.bmp", 1);
		ROCA = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//Roca//piedra.obj", "Modelos//Roca//TexturaRoca.bmp", 1);
		TARIMA = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//Tarima//tarimita.obj", "Modelos//Tarima//texturita.bmp", 1);

		OVEJA1 = new EDXFramework::Model(15, 15, 0, 30, 5, "Modelos//OVEJA//OVEJA1.obj", "Modelos//OVEJA//CASCARA.bmp", 1);
		OVEJA2 = new EDXFramework::Model(15, 15, -180, 30.0f, 75, "Modelos//OVEJA//OVEJA1.obj", "Modelos//OVEJA//CASCARA.bmp", 1);
		OVEJA3 = new EDXFramework::Model(15, 15, -144.0f, 22.0f, -214.0f, "Modelos//OVEJA//OVEJA1.obj", "Modelos//OVEJA//CASCARA.bmp", 1);
	
		GRASS = new EDXFramework::Model(10, 10, -240, 0, -133, "Modelos//pasto//pastin2.obj", "Modelos//pasto//model0.bmp", 1);
		ARBOL = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//tree//arbol2.obj", "Modelos//tree//tree_mat.bmp", 1);
		//CASA
		ESTRUCTURAPEDORRA2 = new EDXFramework::Model(15, 15, 285, 0, -132, "Modelos//estructura//EXTERIOR.obj", "Modelos//estructura//texture2.bmp", 1);
		ESTRUCTURAPEDORRA = new EDXFramework::Model(10,10, 285,0,-132,"Modelos//estructura//INTERIOR.obj", "Modelos//estructura//textureINT.bmp", 1);
		PUENTESILLO = new EDXFramework::Model(23.5, 8.5, 135.5, 34, -89.5, "Modelos//puentesillo//PUENTE.obj", "Modelos//puentesillo//madera.bmp", 1);
		REJA = new EDXFramework::Model(0, 0, 0, 0,0, "Modelos//reja//REJOTA.obj", "Modelos//reja//madera.bmp", 1);
		REJA2 = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//reja//REJA.obj", "Modelos//reja//madera.bmp", 1);
		//CASAS EQUIS
		

		zapatines= new EDXFramework::Model(0, 0, 0, 0, -61, "Modelos//zapatines//zapatos.obj", "Modelos//zapatines//t0195_0.bmp", 1);
		cama = new EDXFramework::Model(5, 8, 292, 0, -61, "Modelos//cama//CAMA.obj", "Modelos//cama//cama.bmp", 1);
		Silla = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//sillaRana//HOLOLA.obj", "Modelos//sillaRana//FroggyChair.bmp", 1);
		Comida = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//comidina//comida.obj", "Modelos//comidina//banquet.bmp", 1);
		Mesa = new EDXFramework::Model(0, 0, 0, 0, 0, "Modelos//MESA//MESITA.obj", "Modelos//MESA//ESMERALDA.bmp", 1);


		//Billboards(m, hWnd);

		cameraInitialize();
	}

	void Billboards(Billboard *bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
	}
	
	void render(HDC hDC)
	{
		skyRotation < 360 ? skyRotation += 0.1f : skyRotation = 0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();
		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);

		py = max(terrain->Superficie(px, pz) * 4 + 6, terrain2->Superficie(px, pz) * 4 + 6);

		//------------------------------puente colision----------------------------
		///  COLISIOn puente
		if (PUENTESILLO->Hitbox(px, pz)) {
			py = 35;

		}

		cameraUpdate();// que tiene que ver el camaraUpdate?

		//////water
		glPushMatrix();
		glTranslatef(-75, 12.0f, -280);
		glScalef(1.3f, 1.3f, 1.8f);
		lago->Draw();

		glPopMatrix();
		//TeMoriste();
		// 
		 
		//////water2
		glPushMatrix();
		//glTranslatef(-47, 15.0f, 167);
		glTranslatef(264, 25.0f, -169);
		glScalef(2.2, 1.3f, 3);
		lago2->Draw();
		glPopMatrix();
		//TeMoriste();

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(skyRotation, 0, 1, 0);
		skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		//glScalef(1, 4, 1);
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();

		//Terreno2
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain2->Draw();
		glPopMatrix();


		////TARIMA
		glPushMatrix();
		glTranslatef(0, 30.0f, 55);
		glScalef(10, 10, 10);
		TARIMA->Draw();
		glPopMatrix();
		//-----------------------------------------piedrass-----------------------------
		//las del lago
		////ROCA
		glPushMatrix();
		glTranslatef(-9, 12.0f, -300);
		glScalef(4, 4, 4);
		ROCA->Draw();
		glPopMatrix();
		////ROCA2
		glPushMatrix();
		glTranslatef(-46, 12.0f, -350);
		glScalef(4, 4, 4);
		ROCA->Draw();
		glPopMatrix();
		////ROCA3
		glPushMatrix();
		glTranslatef(-22, 25.0f, -320);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 4, 4);
		ROCA->Draw();
		glPopMatrix();
		//-----------------------------------------piedras cerca de la bolsa -----------------------------
		////ROCA4
		glPushMatrix();
		glTranslatef(76, 32.0f, 248);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 4, 4);
		ROCA->Draw();
		glPopMatrix();
		////ROCA5
		glPushMatrix();
		glTranslatef(128, 32.0f, 270);
		glScalef(2.5, 2.5, 2.5);
		ROCA->Draw();
		glPopMatrix();
		////ROCA6
		glPushMatrix();
		glTranslatef(129, 32.0f, 277);
		glRotatef(0, 1, 0, 0);
		glScalef(2.5, 2.5, 2.5);
		ROCA->Draw();
		glPopMatrix();
		////ROCA7
		glPushMatrix();
		glTranslatef(139, 32.0f, 205);
		glRotatef(90, 1, 0, 0);
		glScalef(2.5, 2.5, 2.5);
		ROCA->Draw();
		glPopMatrix();
		////ROCA8
		glPushMatrix();
		glTranslatef(95, 32.0f, 168);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		////ROCA9
		glPushMatrix();
		glTranslatef(121, 32.0f, 184);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		////ROCA10
		glPushMatrix();
		glTranslatef(109, 32.0f, 197);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		////ROCA11
		glPushMatrix();
		glTranslatef(74, 32.0f, 200);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		////ROCA12
		glPushMatrix();
		glTranslatef(14, 32.0f, 234);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		////ROCA13
		glPushMatrix();
		glTranslatef(84, 32.0f, 306);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 2.5, 6);
		ROCA->Draw();
		glPopMatrix();
		/////////////////////////////////////////////////////////////////////
		
		//----------------JUGabilida------------
		// 
		//oveja1
		if (eliminarOveja1 == false) {
			glPushMatrix();
			glTranslatef(0, 30,5);
			glScalef(1, 1, 1);
			OVEJA1->Draw();
			glPopMatrix();
		}
		//oveja2
		if (eliminarOveja2 == false) {
			glPushMatrix();
			glTranslatef(-180, 30.0f, 75);
			glScalef(1,1, 1);
			OVEJA2->Draw();
			glPopMatrix();
		}
		//oveja3
		if (eliminarOveja3 == false) {
			glPushMatrix();
			glTranslatef(-144.0f, 22.0f, -214.0f);
			glScalef(1, 1, 1);
			OVEJA3->Draw();
			glPopMatrix();
		}
		//-----------------------------------------pasto-----------------------------------
		glPushMatrix();
		glTranslatef(0, 29.0f, 0);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();
		

		glPushMatrix();
		glTranslatef(211, 29.0f, -31);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(170, 26.0f, -82);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(127, 26.0f, -82);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(170, 26.0f, -100);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(127, 26.0f, -100);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(198, 29.0f, -163);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(331, 29.0f, 54);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(210, 29.0f, 184);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(179, 29.0f, 297);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(29, 29.0f, 304);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(36, 29.0f, 197);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-131, 29.0f, 202);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-133, 29.0f, 221);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-186, 29.0f, 123);
		glScalef(3, 3, 3);
	    GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-335, 29.0f, 54);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-305, 29.0f, -185);
		glScalef(3, 3, 3);
		GRASS->Draw();
		glPopMatrix();
		//-----------------------------------ARBOLES ENORMES PQ SI-------------------
		glPushMatrix();
		glTranslatef(328, 15.0f, -319);
		glScalef(6, 8, 6);
		ARBOL->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.0f, -337);
		glScalef(6, 6, 6);
		ARBOL->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-306, 15.0f, -64);
		glScalef(6, 8, 6);
		ARBOL->Draw();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-248, 15.0f, 304);
		glScalef(4, 6, 4);
		ARBOL->Draw();
		glPopMatrix();

		//-----------------------------------------estructura -----------------------------
		//reja
		glPushMatrix();
		glTranslatef(0, 34, 420);//atras del tornado
		glScalef(1.8f, 1, 1.5);
		REJA->Draw();
		glPopMatrix();
		//reja2
		glPushMatrix();
		glTranslatef(0, 32, -300);//atras del rio
		glScalef(1.8f, 1, 1.5);
		REJA->Draw();
		glPopMatrix();
		//reja3
		glPushMatrix();
		glTranslatef(463, 34, 0);//atras estructura
		glScalef(1.8, 1, 1.8);
		glRotatef(90, 0, 1, 0);
		REJA->Draw();
		glPopMatrix();
		//reja4
		glPushMatrix();//atras de las ovejas
		glTranslatef(-300, 34, 0);
		glScalef(1.8, 1, 1.8);
		glRotatef(90, 0, 1, 0);
		REJA->Draw();
		glPopMatrix();


		//---------------------------- reja -----------------------------------
		glPushMatrix();
		glTranslatef(-100, 30, 100);
		glScalef(0.7f, 0.7f, 0.7f);
		glRotatef(90, 0, 1, 0);
		REJA2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-240, 30, 100);
		glScalef(0.7f, 0.7f, 0.7f);
		glRotatef(90, 0, 1, 0);
		REJA2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-199, 30, 190);
		glScalef(0.8f, 0.7f, 0.7f);
		//glRotatef(0, 0, 1, 0);
		REJA2->Draw();
		glPopMatrix();


		//estructura
		glPushMatrix();
		glTranslatef(296, 33.0f, -132);
		glRotated(-90, 0, 1, 0);
		ESTRUCTURAPEDORRA->Draw();
		ESTRUCTURAPEDORRA2->Draw();
		glPopMatrix();


		//-----------------------------------------casas sin colision -----------------------------
		////PUENTESILLO
		glPushMatrix();
		glTranslatef(145, 29.0f, -90);
		glScalef(3.2, 2.5, 2.5);
		glRotated(-90, 0, 1, 0);
		PUENTESILLO->Draw();
		glPopMatrix();
	

		//-----------------------------------------flores -----------------------------
		//////FLOR3
		FLOR2->animacion();
		glPushMatrix();
		glTranslatef(240, 29.0f, -80);
		glRotated(FLOR2->getRotacion(), 0, 1, 0);
		glScalef(FLOR2->getSx(), FLOR2->getSx(), FLOR2->getSx());
		FLOR2->Draw();
		glPopMatrix();
		//////FLOR4
		glPushMatrix();
		glTranslatef(240, 29.0f, -152);
		glRotated(FLOR2->getRotacion(), 0, 1, 0);
		glScalef(FLOR2->getSx(), FLOR2->getSx(), FLOR2->getSx());
		FLOR2->Draw();
		glPopMatrix();
		//////FLOR
		GRAS1->animacion();
		glPushMatrix();
		glTranslatef(124, 29.0f, -185);
		glRotated(GRAS1->getRotacion(), 0, 1, 0);
		glScalef(GRAS1->getSx(), GRAS1->getSx(), GRAS1->getSx());
		GRAS1->Draw();
		glPopMatrix();
		//////FLOR2
		//FLOR->FlorAni();
		glPushMatrix();
		glTranslatef(92, 29.0f, 12);
		glRotated(GRAS1->getRotacion(), 0, 1, 0);
		glScalef(GRAS1->getSx(), GRAS1->getSx(), GRAS1->getSx());
		GRAS1->Draw();
		glPopMatrix();

		//////BOLSA
		if (eliminarBolsa == false)
		{
			BOLSA->animacion();
			glPushMatrix();
			glTranslatef(118, 41.0f, 236);
			glRotated(BOLSA->getRotacion(), 0, 1, 0);
			glScalef(BOLSA->getSx() - 0.5f, BOLSA->getSx() - 0.5f, BOLSA->getSx() - 0.5f);
			BOLSA->Draw();
			glPopMatrix();
		}

		///ESPIRITU
		ESPIRITU[0]->animacion();
		glPushMatrix();
		//glTranslatef(-21,30, -125);
		glTranslatef(-143, ESPIRITU[0]->getSTy(), -210);
		glScalef(2, 2, 2);
		glRotated(60, 0, 1, 0);
		if (ESPIRITU[0]->getbaila() == true) {
			//baile
			m = m + 0.4f;
			i = m;
			ESPIRITU[i]->Draw();
			if (i >= 9)
			{
				i = 0;
				m = 0;
				ESPIRITU[0]->setbaila(false);
			}
		}
		else {
			ESPIRITU[0]->Draw();
		}
		glPopMatrix();
		if (ESPIRITU[0]->Hitbox(px, pz) == true) {
			int a = 0;
		}

		WOLF[a]->animacion();
		glPushMatrix();
		glTranslatef(164, 40.0f, -305);
		glScalef(WOLF[a]->getSx()*2, WOLF[a]->getSx()*2, WOLF[a]->getSx()*2);
		WOLF[a]->Draw();
		b = b + 0.1f;
		a = b;
		if (a >= 4) {
			a = 0;
			b = 0;
		}
		glPopMatrix();

		//-----------------------------------------	//Tornado -----------------------------
		if (!pause) {
			tornado->animacion();
			glPushMatrix();
			glTranslatef(tornado->getOX(), terrain2->Superficie(tornado->getOX(), tornado->getOz()) * 4, tornado->getOz());
			glRotated(tornado->getRotacion(), 0, 1, 0);
			glScalef(6, 6, 6);
			tornado->Draw();
			glPopMatrix();
		}

		//----------------------------------------/RANA -----------------------------
		if (!pause) {
			RANA->animacion();

			glPushMatrix();
			glTranslatef(RANA->getOX(), RANA->getOy(), 25);
			glScalef(8, 8, 8);
			glRotated(-90, 0, 1, 0);
			glRotated(RANA->getRotacion(), 0, 1, 0);
			RANA->Draw();
			glPopMatrix();
		}

		//////Flechas
		glPushMatrix();
		glTranslatef(109, 25.0f, -75);
		glRotated(-90, 0, 1, 0);
		FLECHAS->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(29, 21.0f, 74);
		glScalef(2, 2, 2);
		glRotated(-180, 0, 1, 0);
		FLECHAS2->Draw();
		glPopMatrix();
		//----------------------------------------Cosas de la casa -----------------------------
		// zapatines
		glPushMatrix();
		glTranslatef(288, 29.0f, -128);
		//glScalef(0.4, 0.4, 0.4);
		glRotated(-90, 0, 1, 0);
		zapatines->Draw();
		glPopMatrix();
		//silla
		glPushMatrix();
		glTranslatef(295, 30.0f, -130);
		glScalef(0.4, 0.4, 0.4);
		glRotated(-90, 0, 1, 0);
		Silla->Draw();
		glPopMatrix();
		//cama
		glPushMatrix();
		glTranslatef(292, 29.0f, -61);
		glRotated(180, 0, 1, 0);
		glScalef(0.4, 0.4, 0.4);
		cama->Draw();
		glPopMatrix();
		//comida
		glPushMatrix();
		glTranslatef(299, 35.0f, -68);
		glRotated(180, 0, 1, 0);
		glScalef(0.2, 0.2, 0.2);
		Comida->Draw();
		glPopMatrix();
		//MESA
		glPushMatrix();
		glTranslatef(300, 34.0f, -66);
		glRotated(180, 0, 1, 0);
		glScalef(0.7, 0.7, 0.7);
		Mesa->Draw();
		glPopMatrix();
		////lobote
		glPushMatrix();
		glTranslatef(25, 34.0f, -242);
		glScalef(4, 4, 4);
		LOBO->Draw();
		glPopMatrix();
		//-----------------------------------agua morir--------------------------------------
		if (py <= 24) {
			
		}

		//-------------------------------------------------COLISIONES--------------------------------------------------------
			//-----------------------------------------estructura -----------------------------
		//estructura para quye este bloqueada hasta que termine de recoger ovejas]
		if (ovejascontar >= 1) { Prende = false; }
			if (Prende == true)
			{
				glPushMatrix();
				if (Privado->HitboxCircular(px, pz)) {
					px = Antx;
					pz = Antz;
					//mostrar bilboard
					MayeTriste->x = Dx;
					MayeTriste->Draw(px, py + 20, pz);
					MayeTriste->z = Dz;
				}
				glPopMatrix();

			}
		if (Prende == false) {

			if ((ESTRUCTURAPEDORRA2->HitboxCircular(px, pz)) && ESTRUCTURAPEDORRA->HitboxCircular(px, pz) == false) {
				if (px <= 291 && px >= 286 && pz > -127) {

				}
				else
					if (pz >= -132 && pz <= -127 && px < 286) {
					}
					else {
						px = Antx;
						pz = Antz;
					}
			}//si jala
			if ((EstructuraColi->HitboxCircular(px, pz)) && EstructuraColi2->HitboxCircular(px, pz) == false) {

				if (px <= 297 && px >= 286 && pz > -97) {
				}
				else {
					px = Antx;
					pz = Antz;
				}

			}

			if (Tunel1->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}
			if (Tunel2->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}

		}
		//------------------------------Ovejas colisiones---------------------------------------
		if (Talar == true) {


			
			//oveja COLISION'
			if (eliminarOveja1 == false) {
				if (OVEJA1->HitboxCircular(px, pz)) {
					px = Antx;
					pz = Antz;
					eliminarOveja1 = true;
					ovejascontar++;
				}
			}
			if (eliminarOveja2 == false) {
				if (OVEJA2->HitboxCircular(px, pz)) {
					px = Antx;
					pz = Antz;
					eliminarOveja2 = true;
					ovejascontar++;
				}
			}
			if (eliminarOveja3 == false) {
				if (OVEJA3->HitboxCircular(px, pz)) {
					px = Antx;
					pz = Antz;
					eliminarOveja3 = true;
					ovejascontar++;

				}
			}

		}
	
		//-------------------------------------reja colision--------------------------------------
		/// REJA COLISION1
		if (py = 34) {
			if (colision2->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}
			/// REJA COLISION2
			if (colision3->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}
			/// REJA COLISION3
			if (colision4->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}
			/// REJA COLISION4
			if (colision5->Hitbox(px, pz)) {
				px = Antx;
				pz = Antz;
			}
		}

		if (rejaC->Hitbox(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		if (rejaC2->Hitbox(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		if (rejaC3->Hitbox(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		//-------------------------------evento climatico----------------------------------------------------
		/// colision niebla
		if (colisiontornado->HitboxCircular(px, pz)) {
			neblina = true;
			lluvia();
			if (neblina) {
				niebla->density = 0.01;
			}
		}
		else {
			neblina = false;
		}
		if (!neblina) {
			niebla->density = 0;
		}
		glPushMatrix();
		niebla->draw();
		glPopMatrix();
		////--------------------------------animaciones colision--------------------------------------------
		 // COLISIOn rana
		if (RANA->Hitbox(px, pz)) {
			px = Antx;
			pz = Antz;
			TeMoriste();
		}
		//---------------------------------flechas colision----------------
		glPushMatrix();
		if (FLECHAS->Hitbox(px, pz)) {	
			game->x = Dx;
			game->Draw(px, py + 40, pz);
			game->z = Dz;
		}
		glPopMatrix();
		//-----------------------------------colision Tornado--------------------------------------------
		if (tornado->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
			TeMoriste();
		}
		
		//-----------------------------------------colision bolsa -----------------------------
		glPushMatrix();
		si = true;
		if (si) {
		
			if (BOLSA->Hitbox(px, pz)) {

				Simon->x = Dx;
				//quiero que elimine 
				Simon->Draw(px, py, pz);
				Simon->z = Dz;
				eliminarBolsa = true;
				Talar = true;
			}
		}
		si == false;
		glPopMatrix();
		//--------------------colision cama == win----------------------------
		if (cama->Hitbox(px, pz)) 
			Win();
		
		
		//-------------------------------------BILBOARdDs-------------------------------------------	
	
		//---------------------------------colision piedras BILBOARdD--------------------------------
		glPushMatrix();
		if (Vida->HitboxCircular(px, pz)) {
			MenosV0->x = Dx;
			MenosV0->Draw(px, py, pz);
			MenosV0->z = Dz;
		}
		glPopMatrix();
		//vida2
		glPushMatrix();
		if (Vida2->HitboxCircular(px, pz)) {
			MenosV01->x = Dx;
			MenosV01->Draw(px, py , pz);
			MenosV01->z = Dz;
		}
		glPopMatrix();
		//vida3
		glPushMatrix();
		if (Vida3->HitboxCircular(px, pz)) {
			MenosV02->x = Dx;
			MenosV02->Draw(px, py , pz);
			MenosV02->z = Dz;
		}
		glPopMatrix();
		//piedra1 ----jala
		glPushMatrix();
		if (PiedraC1->Hitbox(px, pz)) {
			px = Antx;
			pz = Antz;
			MenosV->x = Dx;
			MenosV->Draw(px, py , pz);
			MenosV->z = Dz;
		}
		glPopMatrix();
		//piedra2 no jala
		glPushMatrix();
		if (PiedraC2->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
			MenosV2->x = Dx;
			MenosV2->Draw(px, py+40, pz);
			MenosV2->z = Dz;
		}
		glPopMatrix();
		//piedra3 no jala
		glPushMatrix();
		if (PiedraC3->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
			MenosV3->x = Dx;
			MenosV3->Draw(px, py+40, pz);
			MenosV3->z = Dz;
		}
		glPopMatrix();
		//piedra4 no jala
		glPushMatrix();
		if (PiedraC4->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
			MenosV4->x = Dx;
			MenosV4->Draw(px, py+40, pz);
			MenosV4->z = Dz;
		}
		glPopMatrix();
		//piedra5 no jala
		glPushMatrix();
		if (PiedraC5->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
			MenosV5->x = Dx;
			MenosV5->Draw(px, py+40, pz);
			MenosV5->z = Dz;
		}
		glPopMatrix();
		
		//piedra5 no jala
		glPushMatrix();
		if (PiedraC6->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		glPopMatrix();
		glPushMatrix();
		if (PiedraC7->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		glPopMatrix();
		glPushMatrix();
		if (PiedraC8->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		glPopMatrix();
		glPushMatrix();
		if (PiedraC9->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		glPopMatrix();
		glPushMatrix();
		if (PiedraC10->HitboxCircular(px, pz)) {
			px = Antx;
			pz = Antz;
		}
		glPopMatrix();



		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.

		glPopMatrix();


		SwapBuffers(hDC);



	}

	~Scene()
	{
		//AQUI VAN TODOS LOS PUNTEROS
		delete skyDome;
		delete terrain;
		delete terrain2;
		delete niebla;
		delete nieblaaMBIENTAL;
		delete lago;
		delete lago2;

		//--------------------Estructuras grandes-------------------------------------
		delete ESTRUCTURAPEDORRA;
		delete ESTRUCTURAPEDORRA2;
		delete PUENTESILLO;
		delete REJA;
		
		//-------------------------naturaleza----------------------------------------
		delete LOBO;
		delete ROCA;
		delete TARIMA;


		delete OVEJA1;
		delete OVEJA2;
		delete OVEJA3;
		delete GRASS;
		delete ARBOL;
	
	
		delete GRAS1;
		delete FLOR2;
		delete RANA;
		//------------------------animaciones-----------------------------------------------
		delete FLECHAS;
		delete FLECHAS2;
		for (int i = 0; i < 10; i++)
		{
			delete ESPIRITU[i];
		}
		
		/*for (int a = 0; a < 8; a++)
		{
			delete WOLF[a];
		}*/

		for (int a = 0; a < 5; a++)
		{
			delete WOLF[a];
		}
		delete BOLSA;
		delete tornado;
		//------------------------------cosas de la casa-------------------------------------------------------------
		delete Silla;
		delete cama;
		delete Comida;
		delete Mesa;		
		delete zapatines;
		//------------------------------------delete colisiones-------------------------------------------------------

		delete colision2;
		delete colision3;
		delete colision4;
		delete colision5;
		delete colisionPuente;
		delete bolsaColision;
		delete Privado;
		delete PiedraC1;
		delete PiedraC2;
		delete PiedraC3;
		delete PiedraC4;
		delete PiedraC5;
		delete PiedraC6;
		delete PiedraC7;
		delete PiedraC8;
		delete PiedraC9;
		delete PiedraC10;
		delete Tunel1;
		delete Tunel2;
		delete Vida;
		delete MenosV01;
		delete MenosV02;
		delete rejaC2;
		delete rejaC;
		delete rejaC3;
		//-----------------------------------------bilboards---------------------------------------------------------
		delete game;
		delete Simon;
		delete MenosV0;
		delete MenosV;
		delete MenosV2;
		delete MenosV3;
		delete MenosV4;
		delete MenosV5;
		delete MayeTriste;
		delete khepasoMaster;

		/*for (int i = 0; i <= 4; i++) {
			delete confeti[i];
		}
		for (int i = 0; i <= 3; i++) {
			delete lloraelcielo[i];
		}*/
	}

	void TeMoriste() {
		pause = true;
		glPushMatrix();
		khepasoMaster->x = Dx;
		
		khepasoMaster->z = Dz;
		khepasoMaster->y = 40;
		khepasoMaster->Draw(px, py, pz);
		glPopMatrix();
		//MessageBox(hWnd, "MMste", "Alerta", MB_OK);
		//switch (MessageBox(hWnd, "Volver al inicio?", "Reinicio", MB_YESNO)) {
		//case IDYES: {
		//--------------------ponemos el bilboard que paso master--------
		if (reinicio ) {
			Prende = false;
			Talar = false;
			eliminarBolsa = false;
			eliminarOveja1 = false;
			eliminarOveja2 = false;
			eliminarOveja3 = false;
	
			px = 97;
			pz = -75;
			reinicio = false;
			pause = false;
		}
		//}break;
		//case IDNO: {
		//	DestroyWindow(hWnd);
		//}
		//}
	}
	void Win(){
		pause = true;
		     hf1 = hf1 + 0.2f;
			 hi1 = hf1;
			if (hf1 > 5) {
				hf1 = 0;
				hi1 = 0;
			}
			glPushMatrix();
				confeti[hi1]->x = Dx;
				confeti[hi1]->Draw(px, py, pz);
				confeti[hi1]->z = Dz;

			glPopMatrix();
				if (reinicio) {

					Prende = false;
					Talar = false;
					eliminarBolsa = false;
					eliminarOveja1 = false;
					eliminarOveja2 = false;
					eliminarOveja3 = false;
		

					px = 97;
					pz = -75;
					reinicio = false;
					pause = false;
				}
			//}
			//case IDNO: {
			/*	exit(1);
				DestroyWindow(hWnd);
			}
			}
		*/
	}
	void lluvia() {		
			//billboard de la lluvia
			hf = hf + 0.2f;
			hi = hf;
			if (hf > 4) {
				hf = 0;
				hi = 0;
			}
			glPushMatrix();
			lloraelcielo[hi]->x = px + 10;
			lloraelcielo[hi]->z = pz + 10;
			lloraelcielo[hi]->Draw(px, py, pz);
			glPopMatrix();

			glPushMatrix();
			lloraelcielo[hi]->x = px - 10;
			lloraelcielo[hi]->z = pz - 10;
			lloraelcielo[hi]->Draw(px, py, pz);
			glPopMatrix();

			glPushMatrix();
			lloraelcielo[hi]->x = px - 10;
			lloraelcielo[hi]->z = pz + 10;
			lloraelcielo[hi]->Draw(px, py, pz);
			glPopMatrix();

			glPushMatrix();
			lloraelcielo[hi]->x = px + 10;
			lloraelcielo[hi]->z = pz - 10;
			lloraelcielo[hi]->Draw(px, py, pz);
			glPopMatrix();
		}


};
#endif
