///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "CMP3_MCI.h" ///雙引號, 很像之前 glm.h
CMP3_MCI myMP3; ///宣告一個物件變數
GLuint id1,id2,id3;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * BodyNew = NULL;
GLMmodel * bottom = NULL;
GLMmodel * head = NULL;
GLMmodel * LeftFoot = NULL;
GLMmodel * LeftHand = NULL;
GLMmodel * LeftLegA = NULL;
GLMmodel * LeftLegB = NULL;
GLMmodel * LeftLegC = NULL;
GLMmodel * LeftUpperA = NULL;
GLMmodel * LeftUpperB = NULL;
GLMmodel * RightFoot = NULL;
GLMmodel * RightHand = NULL;
GLMmodel * RightLegA = NULL;
GLMmodel * RightLegB = NULL;
GLMmodel * RightLegC = NULL;
GLMmodel * RightUpperA = NULL;
GLMmodel * RightUpperB = NULL;
GLMmodel * fireball = NULL;
void drawBodyNew(void)
{
    if (!BodyNew) {
	BodyNew = glmReadOBJ("data/BodyNew.obj");
	if (!BodyNew) exit(0);
	glmUnitize(BodyNew);
	glmFacetNormals(BodyNew);
	glmVertexNormals(BodyNew, 10.0);
    }

    glmDraw(BodyNew, GLM_SMOOTH | GLM_TEXTURE);
}
void drawbottom(void)
{
    if (!bottom) {
	bottom = glmReadOBJ("data/bottom.obj");
	if (!bottom) exit(0);
	glmUnitize(bottom);
	glmFacetNormals(bottom);
	glmVertexNormals(bottom, 200.0);
    }

    glmDraw(bottom, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhead(void)
{
    if (!head) {
	head = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 200.0);
    }

    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftUpperB(void)
{
    if (!LeftUpperB) {
	LeftUpperB = glmReadOBJ("data/LeftUpperB.obj");
	if (!LeftUpperB) exit(0);
	glmUnitize(LeftUpperB);
	glmFacetNormals(LeftUpperB);
	glmVertexNormals(LeftUpperB, 200.0);
    }

    glmDraw(LeftUpperB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftUpperA(void)
{
    if (!LeftUpperA) {
	LeftUpperA = glmReadOBJ("data/LeftUpperA.obj");
	if (!LeftUpperA) exit(0);
	glmUnitize(LeftUpperA);
	glmFacetNormals(LeftUpperA);
	glmVertexNormals(LeftUpperA, 200.0);
    }

    glmDraw(LeftUpperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftHand(void)
{
    if (!LeftHand) {
	LeftHand = glmReadOBJ("data/LeftHand.obj");
	if (!LeftHand) exit(0);
	glmUnitize(LeftHand);
	glmFacetNormals(LeftHand);
	glmVertexNormals(LeftHand, 200.0);
    }

    glmDraw(LeftHand, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightUpperB(void)
{
    if (!RightUpperB) {
	RightUpperB = glmReadOBJ("data/RightUpperB.obj");
	if (!RightUpperB) exit(0);
	glmUnitize(RightUpperB);
	glmFacetNormals(RightUpperB);
	glmVertexNormals(RightUpperB, 200.0);
    }

    glmDraw(RightUpperB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightUpperA(void)
{
    if (!RightUpperA) {
	RightUpperA = glmReadOBJ("data/RightUpperA.obj");
	if (!RightUpperA) exit(0);
	glmUnitize(RightUpperA);
	glmFacetNormals(RightUpperA);
	glmVertexNormals(RightUpperA, 200.0);
    }

    glmDraw(RightUpperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightHand(void)
{
    if (!RightHand) {
	RightHand = glmReadOBJ("data/RightHand.obj");
	if (!RightHand) exit(0);
	glmUnitize(RightHand);
	glmFacetNormals(RightHand);
	glmVertexNormals(RightHand, 200.0);
    }

    glmDraw(RightHand, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftLegC(void)
{
    if (!LeftLegC) {
	LeftLegC = glmReadOBJ("data/LeftLegC.obj");
	if (!LeftLegC) exit(0);
	glmUnitize(LeftLegC);
	glmFacetNormals(LeftLegC);
	glmVertexNormals(LeftLegC, 200.0);
    }

    glmDraw(LeftLegC, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftLegB(void)
{
    if (!LeftLegB) {
	LeftLegB = glmReadOBJ("data/LeftLegB.obj");
	if (!LeftLegB) exit(0);
	glmUnitize(LeftLegB);
	glmFacetNormals(LeftLegB);
	glmVertexNormals(LeftLegB, 200.0);
    }

    glmDraw(LeftLegB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftLegA(void)
{
    if (!LeftLegA) {
	LeftLegA = glmReadOBJ("data/LeftLegA.obj");
	if (!LeftLegA) exit(0);
	glmUnitize(LeftLegA);
	glmFacetNormals(LeftLegA);
	glmVertexNormals(LeftLegA, 200.0);
    }

    glmDraw(LeftLegA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLeftFoot(void)
{
    if (!LeftFoot) {
	LeftFoot = glmReadOBJ("data/LeftFoot.obj");
	if (!LeftFoot) exit(0);
	glmUnitize(LeftFoot);
	glmFacetNormals(LeftFoot);
	glmVertexNormals(LeftFoot, 200.0);
    }

    glmDraw(LeftFoot, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightLegC(void)
{
    if (!RightLegC) {
	RightLegC = glmReadOBJ("data/RightLegC.obj");
	if (!RightLegC) exit(0);
	glmUnitize(RightLegC);
	glmFacetNormals(RightLegC);
	glmVertexNormals(RightLegC, 200.0);
    }

    glmDraw(RightLegC, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightLegB(void)
{
    if (!RightLegB) {
	RightLegB = glmReadOBJ("data/RightLegB.obj");
	if (!RightLegB) exit(0);
	glmUnitize(RightLegB);
	glmFacetNormals(RightLegB);
	glmVertexNormals(RightLegB, 200.0);
    }

    glmDraw(RightLegB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightLegA(void)
{
    if (!RightLegA) {
	RightLegA = glmReadOBJ("data/RightLegA.obj");
	if (!RightLegA) exit(0);
	glmUnitize(RightLegA);
	glmFacetNormals(RightLegA);
	glmVertexNormals(RightLegA, 200.0);
    }

    glmDraw(RightLegA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightFoot(void)
{
    if (!RightFoot) {
	RightFoot = glmReadOBJ("data/RightFoot.obj");
	if (!RightFoot) exit(0);
	glmUnitize(RightFoot);
	glmFacetNormals(RightFoot);
	glmVertexNormals(RightFoot, 200.0);
    }

    glmDraw(RightFoot, GLM_SMOOTH | GLM_TEXTURE);
}
void drawfireball(void)
{
    if (!fireball) {
	fireball = glmReadOBJ("data/fireball.obj");
	if (!fireball) exit(0);
	glmUnitize(fireball);
	glmFacetNormals(fireball);
	glmVertexNormals(fireball, 200.0);
    }
    glPushMatrix();
    glScalef(0.05, 0.05, 0.05); /// 將fireball缩小到原来的0.1倍大小
    GLfloat mat_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat mat_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glmDraw(fireball, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
}


///float angle = 0, da = 1; ///加這行, 讓它轉動
float anglex [10] = {}; ///20個角度都設成0
float angley [10] = {};
int angleID = 0; ///可以是角度0、角度1、角度2、......
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){ ///加入mouse motion 對應的函式
    angley [angleID] += y - oldY; /// 當我們的 mouse motion 時, y座標的對應角度
    anglex [angleID] += x - oldX;
    oldX = x;
    oldY = y;
    glutPostRedisplay(); ///要重畫畫面
}

void mouse (int button, int state, int x, int y){
    oldX = x;
    oldY = y;
}

float oldAngleX[10] = {}, newAngleX[10] = {};
float oldAngleY[10] = {}, newAngleY[10] = {};
void timer(int  t){
    glutTimerFunc(25, timer, t+1);
    if(t%20==0){
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0; i<10; i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin, "%f", & newAngleX[i]);
            fscanf(fin, "%f", & newAngleY[i]);
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0;i<10;i++){
        anglex[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
        angley[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y){
    if(key=='p'){
        glutTimerFunc(0, timer, 0);
    }
    if(key=='s'){///貼在這裡
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0;i<10;i++){
            printf("%.1f ", anglex[i]);
            printf("%.1f ", angley[i]);
            fprintf(fout, "%.1f ", anglex[i]);
            fprintf(fout, "%.1f ", angley[i]);
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key=='c') fclose(fout);
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, id3); ///背景
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(-2.5, +2, 0.5);
        glTexCoord2f(0, 1); glVertex3f(-2.5, -2, 0.5);
        glTexCoord2f(1, 1); glVertex3f(+2.5, -2, 0.5);
        glTexCoord2f(1, 0); glVertex3f(+2.5, +2, 0.5);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, id1);
    glPushMatrix();
        glRotatef(anglex[0], 0, 1, 0);
        glScalef(3, 3, 3);
        glTranslatef(0, 0.1, 0);
        drawBodyNew();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glPushMatrix(); ///(0)
            glTranslatef(+0.08, +0.02, -0.01); ///(3)再掛到上手臂的位置
            glRotatef(anglex[2], 1, 0, 0); ///(2)x軸轉
            glTranslatef(0, -0.01, 0); ///(1)
            drawLeftUpperB();
            glPushMatrix(); ///(0)
                glTranslatef(+0.01, -0.1, -0.01); ///(3)再掛到上手臂的位置
                glRotatef(anglex[3], 0, 1, 0); ///(2)x軸轉
                glTranslatef(0, 0, +0.01); ///(1)
                drawLeftUpperA();
                glPushMatrix(); ///(0)
                    glTranslatef(+0.01, -0.07, +0.015); ///(3)再掛到上手臂的位置
                    glRotatef(anglex[4], 0, 1, 0); ///(2)x軸轉
                    glTranslatef(0, 0, +0.01); ///(1)
                    drawLeftHand();
                    glPushMatrix(); ///(0)
                        float k = pow(1.1,anglex[9]);
                        glScalef(k,k,k);
                        glBindTexture(GL_TEXTURE_2D, id2);
                        drawfireball();
                    glPopMatrix(); ///(0)
                glPopMatrix(); ///(0)
            glPopMatrix(); ///(0)
        glPopMatrix(); ///(0)
        glBindTexture(GL_TEXTURE_2D, id1);
        glPushMatrix(); ///(0)
            glTranslatef(-0.08, +0.03, -0.01); ///(3)再掛到上手臂的位置
            glRotatef(angley[2], 1, 0, 0); ///(2)x軸轉
            glTranslatef(0, -0.01, 0); ///(1)
            drawRightUpperB();
            glPushMatrix(); ///(0)
                glTranslatef(-0.05, -0.06, 0); ///(3)再掛到上手臂的位置
                glRotatef(angley[3], 1, 1, 0); ///(2)x軸轉
                glTranslatef(+0.01, 0, +0.01); ///(1)
                drawRightUpperA();
                glPushMatrix(); ///(0)
                    glTranslatef(-0.015, -0.05, +0.015); ///(3)再掛到上手臂的位置
                    glRotatef(angley[4], 0, 1, 0); ///(2)x軸轉
                    glTranslatef(-0.01, 0, +0.01); ///(1)
                    drawRightHand();
                    glPushMatrix(); ///(0)
                        float s = pow(1.1,angley[9]);
                        glScalef(s,s,s);
                        glBindTexture(GL_TEXTURE_2D, id2);
                        drawfireball();
                    glPopMatrix(); ///(0)
                glPopMatrix(); ///(0)
            glPopMatrix(); ///(0)
        glPopMatrix(); ///(0)
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, id1);
    glPushMatrix();
        glTranslatef(0, 0, 0); ///掛在肩上
        glRotatef(angley[0], 0, 1, 0);
        glTranslatef(0, 0, 0);
        glScalef(3, 3, 3);
        drawbottom();
        glPushMatrix(); ///(0)
            glTranslatef(+0.03, -0.04, 0); ///(3)再掛到上手臂的位置
            glRotatef(anglex[5], 1, 0, 0); ///(2)x軸轉
            glTranslatef(0, 0, 0); ///(1)
            drawLeftLegC();
            glPushMatrix(); ///(0)
                glTranslatef(0, -0.06, 0); ///(3)再掛到上手臂的位置
                glRotatef(anglex[6], 1, 0, 0); ///(2)x軸轉
                glTranslatef(0, 0, 0); ///(1)
                drawLeftLegB();
                glPushMatrix(); ///(0)
                    glTranslatef(0, -0.02, 0); ///(3)再掛到上手臂的位置
                    glRotatef(anglex[7], 1, 0, 0); ///(2)x軸轉
                    glTranslatef(0, -0.08, 0); ///(1)
                    drawLeftLegA();
                    glPushMatrix(); ///(0)
                        glTranslatef(+0.01, -0.08, +0.02); ///(3)再掛到上手臂的位置
                        glRotatef(anglex[8], 0, 1, 0); ///(2)x軸轉
                        glTranslatef(0, 0, 0); ///(1)
                        drawLeftFoot();
                    glPopMatrix(); ///(0)
                glPopMatrix(); ///(0)
            glPopMatrix(); ///(0)
        glPopMatrix(); ///(0)
        glPushMatrix(); ///(0)
            glTranslatef(-0.03, -0.04, 0); ///(3)再掛到上手臂的位置
            glRotatef(angley[5], 1, 0, 0); ///(2)x軸轉
            glTranslatef(0, 0, 0); ///(1)
            drawRightLegC();
            glPushMatrix(); ///(0)
                glTranslatef(0, -0.06, 0); ///(3)再掛到上手臂的位置
                glRotatef(angley[6], 1, 0, 0); ///(2)x軸轉
                glTranslatef(0, -0.08, 0); ///(1)
                drawRightLegB();
                glPushMatrix(); ///(0)
                    glTranslatef(0, 0.05, 0); ///(3)再掛到上手臂的位置
                    glRotatef(angley[7], 1, 0, 0); ///(2)x軸轉
                    glTranslatef(0, -0.08, 0); ///(1)
                    drawRightLegA();
                    glPushMatrix(); ///(0)
                        glTranslatef(0, -0.07, 0); ///(3)再掛到上手臂的位置
                        glRotatef(angley[8], 0, 1, 0); ///(2)x軸轉
                        glTranslatef(0, 0, 0); ///(1)
                        drawRightFoot();
                    glPopMatrix(); ///(0)
                glPopMatrix(); ///(0)
            glPopMatrix(); ///(0)
        glPopMatrix(); ///(0)
    glPopMatrix();

    glPushMatrix(); ///(0)
        glTranslatef(0, +0.55, 0); ///(3)再掛到上手臂的位置
        glRotatef(anglex[1], 0, 1, 0); ///(2)x軸轉
        glRotatef(angley[1], 1 , 0, 0); ///(2)x軸轉
        glTranslatef(0, 0, 0); ///(1)
        glScalef(3, 3, 3);
        drawhead();
    glPopMatrix(); ///(0)



    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void reshape (int w, int h){
    glViewport(0, 0, w, h); ///設定視窗會看到的區域
    float ar = w / (float) h; ///長寬比、寬長比
    glMatrixMode(GL_PROJECTION); ///切換投影矩陣
    glLoadIdentity();
    gluPerspective( 60, ar, 0.01, 100); ///透視投影
    glMatrixMode(GL_MODELVIEW); ///切換 model view 矩陣
    glLoadIdentity();
    gluLookAt(0, 0,-2,  0, 0, 0,  0, 1, 0);
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(1200, 795);
    glutCreateWindow("Final");
    myMP3.Load("song.mp3");
    myMP3.Play();
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse); ///滑鼠點下去, 滑鼠拖曳, 滑鼠拿起來
    glutMotionFunc(motion); ///滑鼠控制
    glutKeyboardFunc(keyboard); ///week13-1新加的
    glutReshapeFunc(reshape);

    id1 = myTexture("data/color.jpg");
    id2 = myTexture("data/fire.jpg");
    id3 = myTexture("data/background.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
