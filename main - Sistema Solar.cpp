#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#define PI 3.14159265f 
#include <math.h>

#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h> 

#include <stdio.h>
#include "texture.h"

float scale = 0.16f;
float rot = 0;
float rotTex = 0;
float transX = 0;
float transY = 0;
bool paused = false;



float angLua = 2 * PI;
float angMar = 2 * PI;
float angMer = 2 * PI;
float angVen = 2 * PI;
float angTer = 2 * PI;
float angSat = 2 * PI;
float angUra = 2 * PI;
float angJup = 2 * PI;
float angNet = 2 * PI;
float angPlu = 2 * PI;



// raio dos astros
float sol = 5.453904f;
float mer = 0.0382565f;
float ven = 0.0948886f;
float ter = 0.1f;
float lua = 0.0136117f;
float mar = 0.0532612f;
float jup = 1.121041f;
float sat = 0.9407337f;
float anel = 1.3f;
float ura = 0.399811f;
float net = 0.388052f;
float plu = 0.017846f;


// Criação das texturas dos astros
Texture texSol, texMer, texVen, texTer, texLua, texMar, texCin, texJup, texSat, texAnel, texUra, texNet, texPlu;


// Distâncias entre os astros
float dMer = 6.0f;
float dVen = dMer + 0.45f;
float dTer = dVen + 0.45f;
float dLua = 0.18f;
float dMar = dTer + 0.75f;
float dCin = dMar + 2.625f;
float dJup = dMar + 5.25f;
float dSat = dJup + 6.75f;
float dAnel = dSat + 0.02f;
float dUra = dSat + 14.25f;
float dNet = dUra + 16.5f;
float dPlu = dNet + 14.4f;


void drawAstro(float r, Texture tex)
{
	tex.Use();
	glBegin(GL_POLYGON);
	for (float ang = 0; ang <= 2 * PI; ang += 0.01f)
	{
		float x = r*sin(ang);
		float y = r*cos(ang);
		float s = 0.5*sin(ang) + 0.5;
		float t = 0.5*cos(ang) + 0.5;
		glTexCoord2f(s, t);
		glVertex2f(x, y);
	}
	glEnd();
}



void drawOrbit(float r)
{
	
	glDisable(GL_TEXTURE_2D);
	/*glLineStipple(1, 0x00FF);
	glEnable(GL_LINE_STIPPLE);*/
	glBegin(GL_LINE_LOOP);
	for (float ang = 0; ang <= 2 * PI; ang += 0.01f)
	{
		float x = r*sin(ang);
		float y = r*cos(ang);
		glVertex2f(x, y);
	}
	glEnd();
	glEnable(GL_TEXTURE_2D);
}


void display()
{

	glClearColor(0, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rot, 0, 0, 1);
	glScalef(scale, scale, 1);
	glTranslatef(transX, transY, 1);

	glColor3f(1, 1, 1);


	// Cinturao
	glPushMatrix();
	glRotatef(-angSat*50, 0, 0, 1);
	drawAstro(dCin, texCin);
	glPopMatrix();

	// Sol
	glPushMatrix();
	drawAstro(sol, texSol);
	glColor3f(0.6, 0.6, 0.6);
	drawOrbit(dMer);
	drawOrbit(dVen);
	drawOrbit(dTer);
	drawOrbit(dMar);
	drawOrbit(dJup);
	drawOrbit(dSat);
	drawOrbit(dUra);
	drawOrbit(dNet);
	drawOrbit(dPlu);
	glColor3f(1, 1, 1);
	glPopMatrix();


	// Mercúrio
	glPushMatrix();
	glRotatef(angTer, 0, 0, 1);
	glTranslatef(dMer * cos(angMer), dMer * sin(angMer), 0);
	drawAstro(mer, texMer);
	glPopMatrix();

	// Venus
	glPushMatrix();
	glTranslatef(dVen * cos(angVen), dVen * sin(angVen), 0);
	drawAstro(ven, texVen);
	glPopMatrix();

	// Terra
	glPushMatrix();
	glTranslatef(dTer* cos(angTer), dTer * sin(angTer), 0);
	drawAstro(ter, texTer);

	// Lua
	glPushMatrix();
	drawOrbit(dLua);
	glTranslatef(dLua * cos(angLua), dLua * sin(angLua), 0);
	drawAstro(lua, texLua);
	glPopMatrix();
	glPopMatrix();

	// Marte
	glPushMatrix();
	glTranslatef(dMar * cos(angMar), dMar * sin(angMar), 0);
	drawAstro(mar, texMar);
	glPopMatrix();

	// Jupiter
	glPushMatrix();
	glTranslatef(dJup * cos(angJup), dJup * sin(angJup), 0);
	drawAstro(jup, texJup);
	glPopMatrix();

	// Saturno e seus aneis
	glPushMatrix();
	glTranslatef(dSat * cos(angSat), dSat * sin(angSat), 0);
	drawAstro(anel, texAnel);
	drawAstro(sat, texSat);
	glPopMatrix();

	// Urano
	glPushMatrix();
	glTranslatef(dUra * cos(angUra), dUra * sin(angUra), 0);
	drawAstro(ura, texUra);
	glPopMatrix();

	// Netuno
	glPushMatrix();
	glTranslatef(dNet * cos(angNet), dNet * sin(angNet), 0);
	drawAstro(net, texNet);
	glPopMatrix();

	// Plutao
	glPushMatrix();
	glTranslatef(dPlu * cos(angPlu), dPlu * sin(angPlu), 0);
	drawAstro(plu, texPlu);
	glPopMatrix();


	glutSwapBuffers();

	glutPostRedisplay();

	if (paused != true)
	{
		angLua -= 1.2424446;
		angMar -= 0.00080849f;
		angMer -= 0.00160745f;
		angVen -= 0.00117595f;
		angTer -= 0.001f;
		angSat -= 0.00032538f;
		angUra -= 0.00022867f;
		angJup -= 0.00043888f;
		angNet -= 0.00018233f;
		angPlu -= 0.00017846f;
	}

}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

void keypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		scale += 0.01;
		break;
	case 'f':
		scale -= 0.01;
		if (scale < 0.01)
		{
			scale = 0.01;
		}
		break;
	case 's':
		transY += 0.35;
		break;
	case 'w':
		transY -= 0.35;
		break;
	case 'd':
		transX -= 0.15;
		break;
	case 'a':
		transX += 0.15;
		break;
	case 'p':
		paused = !paused;
		break;
	case 'o':
		scale = 0.16;
		angLua = 0;
		angMar = 0;
		angMer = 0;
		angVen = 0;
		angTer = 0;
		angSat = 0;
		angUra = 0;
		angJup = 0;
		angNet = 0;
		angPlu = 0;
		break;
	}
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);

	glutCreateWindow("Sistema Solar");
	glutReshapeFunc(reshape);

	glutDisplayFunc(display);
	glutKeyboardFunc(keypress);
	glEnable(GL_TEXTURE_2D);

	texSol.Load("sol.bmp");
	texMer.Load("mercurio.bmp");
	texVen.Load("venus.bmp");
	texTer.Load("terra.bmp");
	texLua.Load("lua.bmp");
	texMar.Load("marte.bmp");
	texCin.Load("cinturao.bmp");
	texJup.Load("jupiter.bmp");
	texSat.Load("saturno.bmp");
	texAnel.Load("anel.bmp");
	texUra.Load("urano.bmp");
	texNet.Load("netuno.bmp");
	texPlu.Load("plutao.bmp");

	glutMainLoop();
	return 0;
}