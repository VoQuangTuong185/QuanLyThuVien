using namespace std;
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>

#include "define.h"
#include "datetime.h"
#include "queue.h"
#include "cautrucdulieu.h"
#include "view.h"
#include "local.h"
#include "dausachvasach.h"
#include "docgia.h"
#include "muontra.h"

#include "nhapxuat.h"

int main(int argc, char *argv[]){
	initwindow(w, h, AppTitle);			// init window graphics
	ClearScreen(0);
	DS_DauSach DSDS; //DSDS quan ly ca dau sach + sach
	TreeDocgia DSDG; //DSDS quan ly ca dau doc gia + muon sach
	ReadDauSachFromFile(DSDS);
	ReadDocGiaFromFile(root);
	//CreateFileMaTheDocGia();
	int TheDocGiaBSTC[MAX_DOC_GIA];
	TDGTS_PTR tdg = NULL;
	ReadMaTheDocGia(tdg);
	DrawMenu();
	while(true){
		Event(DSDS,DSDG, tdg);
		if(isExit) break;
		delay(100);
	}
	closegraph();
	return 0;
}



