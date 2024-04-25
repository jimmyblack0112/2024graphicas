 #include <GL/glut.h>

 void myBody(){///�ڪ�����
    glPushMatrix();
        glColor3f(1, 0, 0);///���⪺
        glutWireCube(0.6);///myBody()
    glPopMatrix();
 }
void myArm(){///�ڪ�����
    glPushMatrix();
        glColor3f(0, 1, 0);///��⪺
        glScalef(1, 0.4, 0.4);///�j�p
        glutWireCube(0.3);///myArm()
    glPopMatrix();
 }
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    myBody();///�ڪ�����

    glPushMatrix();///�k�b��
        glTranslatef(0.3, 0.3, 0);///(3)����ӤW
        glRotatef(angle, 0, 0, 1);///(2)���ਤ��
        glTranslatef(0.15, 0, 0);///(1)����त�ߩ�b�e����������
        myArm();///�ڪ����u
        glPushMatrix();
            glTranslatef(0.15, 0, 0);///(3)�����y�W
            glRotatef(angle, 0, 0, 1);///(2)���ਤ��
            glTranslatef(0.15, 0, 0);///(1)����त�ߩ�b�e����������
            myArm();///�ڪ����u
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3, 0.3, 0);///(3)����ӤW
        glRotatef(-angle, 0, 0, 1);///(2)���ਤ��
        glTranslatef(-0.15, 0, 0);///(1)����त�ߩ�b�e����������
        myArm();///�ڪ����u
        glPushMatrix();
            glTranslatef(-0.15, 0, 0);///(3)�����y�W
            glRotatef(-angle, 0, 0, 1);///(2)���ਤ��
            glTranslatef(-0.15, 0, 0);///(1)����त�ߩ�b�e����������
            myArm();///�ڪ����u
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
void motion(int x, int y){
    angle = x;
    glutPostRedisplay(); ///�i�DGLUT, �K�W�K�Q�K, ��GLUT���Ů�, �N�n���e�e��
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutIdleFunc(display);///���ŴN����
    glutMainLoop();
}
