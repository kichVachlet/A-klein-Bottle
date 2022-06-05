
/**************************
 * Includes
 *
 **************************/


#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

//Botella de Klein
 #define centro 0
 #define desliza 35
 #define phi 3.14159265358979
 #define dimension 0.08
 
typedef struct _coordenadas_{
	float x,y,z;	
}Cord;

float A=1.9;
void segmento(Cord a, Cord b);
void ejes();
void klein(float a, float r);
void klein2(float a, float r);
void klein3(float a, float r);
void klein4(float a, float r);

//u esta en (0,2pi) , v en (-1,1)
void klein(float a, float r){  //parte superior de la botella

	Cord p1, p2, p3, p4;
	int i,j;
	
	float hu = (2.0*phi)/desliza, hv = phi/desliza;  //2r distancia de -1 a 1
	float u_i, v_j;

	for(i=0; i<desliza ; i++){
		u_i = hu*i;
		for(j=0 ; j<desliza ; j++){
			
			v_j = hv*j;
			p1.x= a+ ( (a+cos(u_i))*cos(v_j) );
			p1.y= sin(u_i);   							
			p1.z= (3.0*phi)+( (a+cos(u_i))*sin(v_j) );
			
			p2.x= a+ ( (a+cos(u_i+hu))*cos(v_j) );
			p2.y= sin(u_i+hu);
			p2.z= (3.0*phi) + ( (a+cos(u_i+hu))*sin(v_j) );
			
			p3.x= a+ ( (a+cos(u_i+hu))*cos(v_j+hv) ); //hv
			p3.y= sin(u_i+hu);
			p3.z= (3.0*phi) + ((a+cos(u_i+hu))*sin(v_j+hv)); //
			
			p4.x= a+ ( (a+cos(u_i))*cos(v_j+hv) ); //quito hu
			p4.y= sin(u_i);
			p4.z= (3.0*phi) + ((a+cos(u_i))*sin(v_j+hv));
			
		/*	glBegin(GL_QUADS); //klein solido
				
				glVertex3f(p1.x, p1.y, p1.z);
				glVertex3f(p2.x, p2.y, p2.z);
				glVertex3f(p3.x, p3.y, p3.z);
				glVertex3f(p1.x, p1.y, p1.z);
			glEnd(); */
			
				segmento(p1,p2); //klein cuadricula
				segmento(p2,p3);
				segmento(p3,p4);
				segmento(p4,p1);
	
		}
	}
	
}


void klein2(float a, float r){ //tubo exterior
	
	Cord p1, p2, p3, p4;
	int i,j;
	
	float hu = (2.0*phi)/desliza, hv = phi/desliza;  //2r distancia de -1 a 1
	float u_i, v_j;
	
	  
	
	for(i=0; i<desliza ; i++){
		u_i = hu*i;
		for(j=0 ; j<desliza ; j++){
			
			v_j = hv*j;
			
			p1.x= (a+0.5+ ((a-0.5)*cos(v_j))) *cos(u_i);
			p1.y= (a+0.5+ ((a-0.5)*cos(v_j))) *sin(u_i);
			p1.z= 3.0*(v_j);
			
		
			p2.x= (a+0.5+ ((a-0.5)*cos(v_j))) *cos(u_i+hu); //hu
			p2.y=(a+0.5+ ((a-0.5)*cos(v_j))) *sin(u_i+hu);
			p2.z= 3.0*(v_j);
			
			p3.x= (a+0.5+ ((a-0.5)*cos(v_j+hv))) *cos(u_i+hu); //hv
			p3.y= (a+0.5+ ((a-0.5)*cos(v_j+hv))) *sin(u_i+hu);
			p3.z= 3.0*(v_j+hv);
			
			p4.x= (a+0.5+ ((a-0.5)*cos(v_j+hv))) *cos(u_i); //sin hu
			p4.y= (a+0.5+ ((a-0.5)*cos(v_j+hv))) *sin(u_i);
			p4.z= 3.0*(v_j+hv);
			
				segmento(p1,p2); //klein cuadricula
				segmento(p2,p3);
			//	segmento(p3,p4);
			//	segmento(p4,p1);
	
		}
	}
	
}

void klein3(float a, float r){ //base de la botella
	
	Cord p1, p2, p3, p4;
	int i,j;
	
	float hu = (2.0*phi)/desliza, hv = phi/desliza;  //2r distancia de -1 a 1
	float u_i, v_j;
	
	  
	
	for(i=0; i<desliza ; i++){
		u_i = hu*i;
		for(j=0 ; j<desliza ; j++){
			
			v_j = hv*j;
			
			p1.x=a-(a*cos(v_j))+sin(u_i);
			p1.y=cos(u_i);
			p1.z=3.0*v_j;
			
			p2.x=a-(a*cos(v_j))+sin(u_i+hu);
			p2.y=cos(u_i+hu);
			p2.z=3.0*v_j;
			
			p3.x=a-(a*cos(v_j+hv))+sin(u_i+hu);
			p3.y=cos(u_i+hu);
			p3.z=3.0*(v_j+hv);
			
			p4.x=a-(a*cos(v_j+hv))+sin(u_i);
			p4.y=cos(u_i);
			p4.z=3.0*(v_j+hv);
			
				segmento(p1,p2); //klein cuadricula
				segmento(p2,p3);
				segmento(p3,p4);
				segmento(p4,p1);
	
		}
	}
	
}


void klein4(float a, float r){ //tubo interior
	
	Cord p1, p2, p3, p4;
	int i,j;
	
	float hu = (2.0*phi)/desliza, hv = phi/desliza;  //2r distancia de -1 a 1
	float u_i, v_j;
	
	  
	
	for(i=0; i<desliza ; i++){
		u_i = hu*i;
		for(j=0 ; j<desliza ; j++){
			
			v_j =  hv*j;
			
			p1.x=(a+0.5+ ((a-0.5)*cos(v_j))) *cos(u_i);
			p1.y=(a+0.5+ ((a-0.5)*cos(v_j))) *sin(u_i);
			p1.z=-2.5*sin(v_j);
			
		
			p2.x=(a+0.5+ ((a-0.5)*cos(v_j))) *cos(u_i+hu); //hu
			p2.y=(a+0.5+ ((a-0.5)*cos(v_j))) *sin(u_i+hu);
			p2.z=-2.5*sin(v_j);
			
			p3.x=(a+0.5+ ((a-0.5)*cos(v_j+hv))) *cos(u_i+hu); //hv
			p3.y=(a+0.5+ ((a-0.5)*cos(v_j+hv))) *sin(u_i+hu);
			p3.z=-2.5*sin(v_j+hv);
			
			p4.x=(a+0.5+ ((a-0.5)*cos(v_j+hv)))*cos(u_i); //sin hu
			p4.y=(a+0.5+((a-0.5)*cos(v_j+hv)))*sin(u_i);
			p4.z=-2.5*sin(v_j+hv);
		

			
				segmento(p1,p2); //klein cuadricula
				segmento(p2,p3);
				segmento(p3,p4);
				segmento(p4,p1);
	
		}
	}
	
}

void segmento(Cord a, Cord b){ //forma vectorial de la recta
	Cord director;
	director.x= b.x - a.x; director.y= b.y - a.y; director.z= b.z - a.z;
	
	double norma= sqrt((director.x*director.x)+(director.y*director.y)+(director.z*director.z));
	//director.x= director.x/norma; director.y= director.y/norma; director.z= director.z/norma;
	
	int t;
	
		double equis, ye, zeta,
			   equis1, ye1, zeta1;
		
	    glBegin(GL_LINES);   
   		glLineWidth(8.0);   
    	glColor3f(4.0f, 10.0f, 10.0f);     

        
         equis = dimension*(centro+a.x+director.x);
        ye = dimension*(centro+a.y+director.y);
        zeta = dimension*(centro+a.z+director.z);
        
        equis1= dimension*(centro+a.x);
		ye1= dimension*(centro+a.y);
		zeta1= dimension*(centro+a.z);
        
      	glVertex3f(equis,ye,zeta);
      	glVertex3f(equis1,ye1,zeta1); 
      /*	glVertex3f(centro+a.x+director.x,centro+a.y+director.y,centro+a.z+director.z);
      	glVertex3f(centro+a.x,centro+a.y,centro+a.z); */
      	glEnd();

}

void ejes(){
	   glBegin(GL_LINES);   
    glLineWidth(8.0);   //----no sirve

        glColor3f(0.0f, 10.0f, 0.0f);     // Green
      glVertex3f(centro,centro,centro);
        glVertex3f(centro+5.0,centro,centro);
            glColor3f(1.0f, 0.0f, 0.0f);     // Red
     glVertex3f(centro,centro,centro);
      glVertex3f(centro,centro+5.0,centro);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(centro,centro,centro);
       glVertex3f(centro,centro,centro+5.0);
       
    glEnd();

    
}


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Klein";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "Klein", "Klein", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 1056, 1056, //valores pantalla
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            //------------------código-----------

            
            //glClearColor (1.0f, 1.0f, 1.0f, 0.5f);
            glClear (GL_COLOR_BUFFER_BIT);
            glPushMatrix ();
            glRotatef (-theta/2.5, 0.75f, 0.75f, 0.7f);
            
			//ejes();
		    //segmento(a,b);
		    klein(1.8, 1.3);
		    klein2(1.8, 1.3);
		    klein3(1.8, 1.3);
		    klein4(1.8, 1.3);
			
		    glPopMatrix ();
            SwapBuffers (hDC);
            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}

