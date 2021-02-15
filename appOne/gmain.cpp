#include"libOne.h"
void gmain() {
#ifdef _DEBUG
    //�w��t�H���_���̑S�Ẵt�@�C�����p�b�P�[�W������
    //�����́u�p�b�P�[�W�t�@�C�����v�ɂ͑Ή����Ă��Ȃ�
    //Release���[�h�ł͂�����ʂ�Ȃ�
    createPackage("assets", "janken.pac");
#endif

    //�E�B���h�E�\����łȂ���loadImage��loadSound�͎g���Ȃ�
    window(300, 300);

    //�p�b�P�[�W�̓ǂݍ���
    loadPackage("janken.pac");
    //�摜�E���A�ǂݍ���
    //���t�H���_���ƃt�@�C������\\�łȂ��Ȃ���΂Ȃ�Ȃ�
    //��loadPackage���Ȃ���Ε��ʂɃt�@�C������ǂݍ���
    int guImg       = loadImage("assets\\images\\playerGu.png");
    int chokiImg    = loadImage("assets\\images\\playerChoki.png");
    int paImg       = loadImage("assets\\images\\playerPa.png");
    const int numPonSnd = 3;
    int ponSnd[numPonSnd] = { loadSound("assets\\sounds\\pon.wav") };
    int tuzumiSnd = loadSound("assets\\sounds\\tuzumi.wav");
    //���ׂĂ̓ǂݍ��݂��I�������A����Ƀp�b�P�[�W���J�����邱��
    deletePackage();

//---------------�ȏオ�p�b�P�[�W�̎g����----------------------------------

    //�Ƃ肠�����Â݂�炷
    playSound(tuzumiSnd);

    //�������𓯎��ɖ炷���߁A���𕡐�����
    ponSnd[1] = duplicateSound(ponSnd[0]);
    ponSnd[2] = duplicateSound(ponSnd[0]);
    int ponSndIdx = 0;

    //�摜�p�f�[�^
    int img = paImg;
    float alpa = 55;

    rectMode(CENTER);
    while (notQuit) {
        //update-----------------------------------------------------------
        if (isTrigger(KEY_Z) || isTrigger(KEY_X) || isTrigger(KEY_C)) {
            //�|��
            playSound(ponSnd[ponSndIdx]);
            ++ponSndIdx %= numPonSnd;
            //�摜�؂�ւ�
            if (isTrigger(KEY_Z))img = guImg;
            if (isTrigger(KEY_X))img = chokiImg;
            if (isTrigger(KEY_C))img = paImg;
            alpa = 255;
        }
        //������������
        if (alpa > 55) { 
            alpa -= 2;
        }
        //draw-------------------------------------------------------------
        clear(50);
        //��
        imageColor(255, 255, 255, alpa);
        image(img, width / 2, height / 2);
        //�����e�L�X�g
        text("Z:�O�[ X:�`���L C:�p�@",40,height-20);
    }
}