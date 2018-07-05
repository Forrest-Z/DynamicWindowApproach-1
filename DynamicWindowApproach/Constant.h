#include <iostream>
#include <vector>

using namespace std;

#define M_PI 3.1415927
#define MAX_VELOCITY 1.0						//���ι켣������ٶ�
#define MIN_VELOCITY 0							//���ι켣����С�ٶ�
#define MAX_OMEGA 20.0 / 180.0 * M_PI			//���ι켣�������ٶ�
#define MIN_OMEGA 0								//���ι켣����С���ٶ�
#define MAX_ACCELERATE 0.2						//��̬���ڣ������ٶ�
#define MAX_ACCOMEGA 50.0 / 180.0 * M_PI		//��̬���ڣ����Ǽ��ٶ�
#define SAMPLING_VELOCITY 0.01					//�ٶȲ������
#define SAMPLING_OMEGA 1 / 180.0 * M_PI			//���ٶȲ������
#define DT 0.1									//����ʱ����
#define PREDICT_TIME 3.0						//Ԥ��ʱ��
#define WEIGHT_HEADING 0.05						//HEADINGȨ��
#define WEIGHT_CLEARANCE 0.2					//CLEARANCEȨ��
#define WEIGHT_VELOCITY 0.1						//VELOCITYȨ��
#define GOAL_X 10								//Ŀ�������
#define GOAL_Y 10								//Ŀ��������
#define ROBOT_RADIUS 0.5						//�����˰뾶


struct RobotState
{
	// x���꣬y���꣬���������ٶȣ����ٶ�
	float xPosition, yPosition, orientation, velocity, omega;
};

// �ϰ���
int obstacle[18][2] = { { 0, 2 },
							{ 4, 2 },
							{ 4, 4 },
							{ 5, 4 },
							{ 5, 5 },
							{ 5, 6 },
							{ 5, 9 },
							{ 8, 8 },
							{ 8, 9 },
							{ 7, 9 },
							{ 6, 5 },
							{ 6, 3 },
							{ 6, 8 },
							{ 6, 7 },
							{ 7, 4 },
							{ 9, 8 },
							{ 9, 11 },
							{ 9, 6 } };

struct EvaluationPara
{
	float heading, clearance, velocity, v, w;
};