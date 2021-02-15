#include"libOne.h"
void gmain() {
#ifdef _DEBUG
    //指定フォルダ内の全てのファイルをパッケージ化する
    //複数の「パッケージファイル化」には対応していない
    //Releaseモードではここを通らない
    createPackage("assets", "janken.pac");
#endif

    //ウィンドウ表示後でないとloadImageとloadSoundは使えない
    window(300, 300);

    //パッケージの読み込み
    loadPackage("janken.pac");
    //画像・音、読み込み
    //※フォルダ名とファイル名は\\でつなげなければならない
    //※loadPackageしなければ普通にファイルから読み込む
    int guImg       = loadImage("assets\\images\\playerGu.png");
    int chokiImg    = loadImage("assets\\images\\playerChoki.png");
    int paImg       = loadImage("assets\\images\\playerPa.png");
    const int numPonSnd = 3;
    int ponSnd[numPonSnd] = { loadSound("assets\\sounds\\pon.wav") };
    int tuzumiSnd = loadSound("assets\\sounds\\tuzumi.wav");
    //すべての読み込みが終わったら、直後にパッケージを開放すること
    deletePackage();

//---------------以上がパッケージの使い方----------------------------------

    //とりあえずつづみを鳴らす
    playSound(tuzumiSnd);

    //同じ音を同時に鳴らすため、音を複製する
    ponSnd[1] = duplicateSound(ponSnd[0]);
    ponSnd[2] = duplicateSound(ponSnd[0]);
    int ponSndIdx = 0;

    //画像用データ
    int img = paImg;
    float alpa = 55;

    rectMode(CENTER);
    while (notQuit) {
        //update-----------------------------------------------------------
        if (isTrigger(KEY_Z) || isTrigger(KEY_X) || isTrigger(KEY_C)) {
            //ポン
            playSound(ponSnd[ponSndIdx]);
            ++ponSndIdx %= numPonSnd;
            //画像切り替え
            if (isTrigger(KEY_Z))img = guImg;
            if (isTrigger(KEY_X))img = chokiImg;
            if (isTrigger(KEY_C))img = paImg;
            alpa = 255;
        }
        //少しずつ透明化
        if (alpa > 55) { 
            alpa -= 2;
        }
        //draw-------------------------------------------------------------
        clear(50);
        //手
        imageColor(255, 255, 255, alpa);
        image(img, width / 2, height / 2);
        //説明テキスト
        text("Z:グー X:チョキ C:パァ",40,height-20);
    }
}