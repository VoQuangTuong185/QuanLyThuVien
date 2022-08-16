struct SachMT{
	char MASACH[15];
	char TenSach[30];
	char NgayMuon[10];
	int TrangThai;
};

struct DSMuonTra{
	int n;
	SachMT *mt = new SachMT[3];
	
	DSMuonTra(){
		n = 0;
	}
	~DSMuonTra(){
		delete[] mt;
	}
};

DSMuonTra DSMTS;

void DrawTopTen(DS_DauSach &DSDS){
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy(w/2 - textwidth(TopTen)/2-85, 15, TopTen);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(150, 180, w, h);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	char t[][20] = {"STT", "ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai", "So luot muon"};	
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	bar(MUONTRA[0], 250, MUONTRA[8], 320);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setlinestyle(SOLID_LINE,0, 3);
	setcolor(BG_COLOR);
	for(int i=0; i<8; i++)
		outtextxy((MUONTRA[i+1]+MUONTRA[i])/2 - textwidth(t[i])/2, 285-textheight(t[i])/2, t[i]);
	
	setbkcolor(BG_COLOR);	
	//COTMUONTRA
	setcolor(BORDER_COLOR);
	rectangle(MUONTRA[0], 250, MUONTRA[8], 850);	
	for(int i=0; i < 7; i++){
		setlinestyle(SOLID_LINE, 0, 1);
		line(MUONTRA[i+1], 250, MUONTRA[i+1], 850);
	}	
	TopSach topsach(DSDS);
	char ch[20];
	for(int i=0; i < (topsach.n < 10 ? topsach.n : 10); i++){
		itoa(i+1, ch, 10);//STT																
		outtextxy((MUONTRA[0]+MUONTRA[1])/2-textwidth(ch)/2, 350 + i*50, ch);
		outtextxy(MUONTRA[1]+10, 350 + i*50, DSDS.nodes[topsach.list[i].indexDS]->ISBN);		
		outtextxy(MUONTRA[2]+10, 350 + i*50, DSDS.nodes[topsach.list[i].indexDS]->tensach);
				
		itoa(DSDS.nodes[topsach.list[i].indexDS]->sotrang, ch, 10);		
		outtextxy(MUONTRA[3]+20, 350 + i*50, ch);		
		outtextxy(MUONTRA[4]+10, 350 + i*50, DSDS.nodes[topsach.list[i].indexDS]->tacgia);
				
		itoa(DSDS.nodes[topsach.list[i].indexDS]->nxb, ch, 10);			
		outtextxy((MUONTRA[5]+MUONTRA[6])/2-textwidth(ch)/2, 350 + i*50, ch);	
		outtextxy(MUONTRA[6]+10, 350 + i*50, DSDS.nodes[topsach.list[i].indexDS]->theloai);
				
		itoa(topsach.list[i].count, ch, 10);							
		outtextxy((MUONTRA[7]+MUONTRA[8])/2-textwidth(ch)/2, 350 + i*50, ch);
	} 
}

void DrawTraSach(){	
	btnTraSach.isHover = true;
	btnTraSach.isChoose = true;
	btnTraSach.draw();
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy(w/2 - textwidth(DauSachTitle)/2, 15, TraSach);
	
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
}

void DrawTrangConDSMT(DS_DauSach &DSDS){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(15, 130, w, h);//clear phan duoi cua trang tu thanh tim kiem
	bar(w/2-400, 15, w/2+400, 65);//clear tieu de
	btnMuonSach.isChoose = false;
	btnTraSach.isChoose = false;
	btnTopTen.isChoose = false;	
	if(Window == MUON_SACH){
		btnMuonSach.isChoose = true;
		DrawMuonSach();
	}
	else if(Window == TRA_SACH){
		btnTraSach.isChoose = true;
		DrawTraSach();
	}
	else if(Window == TOP_TEN){
		btnTopTen.isChoose = true;
		DrawTopTen(DSDS);
	}
}

int GetItemMTPosition(int y){
	int pos = (y-625+8)/40;
	if(pos >= DSMTS.n) return -1;
	return pos;
}

void DrawBorderDSMT(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(BORDER_COLOR);
	setbkcolor(BG_COLOR);
	char t[4][15] = {"Ma sach", "Ten sach", "Ngay muon", "Trang thai"};
	setfillstyle(SOLID_FILL, BORDER_COLOR);
	rectangle(150, 275, 800, 500);//khung thong tin doc gia
	rectangle(XMT[0], 550, XMT[4], 775);//khung DSMT
	if (Window == MUON_SACH)//chi ve khung thong bao cho window MUON_SACH
		rectangle(170, 875, 845, 975);
	
	int yline = 600;
	line(XMT[0], yline, XMT[4], yline);
	for(int i=0; i<4; i++){
		line(XMT[i], 550, XMT[i], 775);
		outtextxy((XMT[i]+XMT[i+1])/2 - textwidth(t[i])/2, (550+yline)/2-textheight(t[i])/2, t[i]);
	}
}

void DrawItemMT(int i){
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor((DSMTS.mt[i].TrangThai == 2) ? PANEL: TEXT_COLOR_SELECTED);	
	outtextxy(XMT[0]+10, 625+i*40, DSMTS.mt[i].MASACH);
	outtextxy(XMT[1]+10, 625+i*40, DSMTS.mt[i].TenSach);
	outtextxy(XMT[2]+10, 625+i*40, DSMTS.mt[i].NgayMuon);
	outtextxy(XMT[3]+10, 625+i*40, TTMuonTra[DSMTS.mt[i].TrangThai]);
}

void DrawLineSachMuon(bool current){
	setfillstyle(SOLID_FILL, current ? LINE: BG_COLOR);
	bar(XMT[0], 625 + CurrentItemMT*40 - 8, XMT[4], 625+(CurrentItemMT+1)*40-8);			
	setbkcolor(current ? LINE: BG_COLOR);
	DrawItemMT(CurrentItemMT);			
	DrawBorderDSMT();
}

void ItemSachMuonEvent(){
	if(mx > XMT[0] && mx < XMT[4] && my > 625-8 && my < 745-8){
		if(CurrentItemMT != GetItemMTPosition(my)){
			// khoi phuc item
			if(CurrentItemMT != -1)
				DrawLineSachMuon(false);
					
			CurrentItemMT = GetItemMTPosition(my);
			
			// Ve item hien tai
			if(CurrentItemMT != -1)
				DrawLineSachMuon(true);
		}
	}else
		if(CurrentItemMT != -1){
			// khoi phuc item
			DrawLineSachMuon(false);
			CurrentItemMT = -1;
		}
}

bool isDGQH(DS_DauSach &DSDS, TreeDocgia &DSDG){
    if(CurrentDGMT->mt.chuaTra > 0){	
        DSMTS.n = CurrentDGMT->mt.chuaTra;
        int i = DSMTS.n-1;
        for(PTRMT mt = CurrentDGMT->mt.First; mt != NULL; mt = mt->next){
            if(mt->muontra.trangthai == 0)
                if(DiffTime(GetSystemDate(), mt->muontra.ngaymuon) > 6*24*60*60)
                    return true;
        }
    }   
    return false;
}

void DrawThongTinDocGia(DS_DauSach &DSDS, TreeDocgia &DSDG){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(15, 210, w, h);//clear phan duoi cua trang tu thanh tim kiem
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	if(CurrentDGMT == NULL){
		setcolor(TIPS);
		outtextxy(w/2 - 240, 210, "KHONG TIM THAY DOC GIA");
	}else{	
		char ch[30];
		setcolor(TEXT_COLOR);
		outtextxy(225, 300, "Doc gia :");
		outtextxy(225, 350, "Ma the :");
		outtextxy(225, 400, "Phai :");
		outtextxy(225, 450, "Trang thai the :");
			
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(350, 250, "THONG TIN DOC GIA");
		setcolor(TEXT_COLOR_SELECTED);	
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);		
			
		sprintf(ch, "%s %s", CurrentDGMT->ho, CurrentDGMT->ten);		
		outtextxy(500, 300, ch);		
				
		sprintf(ch, "%d", CurrentDGMT->MATHE);						
		outtextxy(500, 350, ch);	
					
		outtextxy(500, 400, PhaiDocGia[CurrentDGMT->phai]);	
			
		setcolor((CurrentDGMT->trangthai == 0) ? PANEL: TEXT_COLOR_SELECTED);	
		outtextxy(500, 450, TTTDocGia[CurrentDGMT->trangthai]);	
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);		
		setcolor(TEXT_COLOR);				
			
		outtextxy((XMT[0]+XMT[4])/2 - textwidth(DSDM)/2, 522, DSDM);
		setlinestyle(SOLID_LINE,0, 3);		
		DrawBorderDSMT();
		(Window == MUON_SACH) ? btnTraNgay.draw() : btnMuonNgay.draw();
	    DSMTS.n = 0;
	    DauSach *ds;
	    if(CurrentDGMT->mt.chuaTra > 0){	
	        DSMTS.n = CurrentDGMT->mt.chuaTra;
	        int i = DSMTS.n-1;
	        for(PTRMT mt = CurrentDGMT->mt.First; mt != NULL; mt = mt->next){
	            if(mt->muontra.trangthai != 1){
	                ds = GetDauSach(DSDS, mt->muontra.MASACH);
	                strcpy(DSMTS.mt[i].MASACH, mt->muontra.MASACH);
	                strcpy(DSMTS.mt[i].TenSach, ds->tensach);
	                strcpy(DSMTS.mt[i].NgayMuon, mt->muontra.ngaymuon);
	                DSMTS.mt[i].TrangThai = mt->muontra.trangthai;
	                DrawItemMT(i--);
	            }
	        }
	    } 

		if(Window == MUON_SACH){
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(205, 880, 845, 970);//khung thong bao
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);	
			// the bi khoa
			if(isDGQH(DSDS, DSDG)){
				setcolor(TIPS);
				outtextxy(200, 900, "       DOC GIA DA MUON SACH QUA 7 NGAY ");
				outtextxy(200, 925, "  VUI LONG TRA SACH TRUOC KHI MUON SACH MOI");
				CurrentDGMT->trangthai = 0;
				return;
			}	
		    else if (CurrentDGMT->trangthai == 0){
		    	setcolor(TIPS);
		    	outtextxy(200, 910, "THE DOC GIA DANG BI KHOA, KHONG THE MUON SACH");
			    return;
			}			
			else if(DSMTS.n >= 3){
				setcolor(TIPS);
				outtextxy(200, 900, "SO LUONG SACH MUON DA DAT GIOI HAN !");
				outtextxy(200, 925, "VUI LONG TRA SACH TRUOC KHI MUON SACH MOI");
				return;
			}
			else {
				btnTimMaSach.draw();
				edNhapMaSachMuonSach.draw();
				canBorrow = true;
				setcolor(TEXT_COLOR_SELECTED);
				outtextxy(275, 912, "THE DOC GIA CUA BAN CO THE MUON SACH");
			}		
		}
		else{
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);		
			setcolor(TEXT_COLOR);
			outtextxy(240, 900, "LUU Y: CLICK CHUOT TRAI DE CHON SACH");
		}
	}
}

void DrawLamMatSach(){
	setcolor(TEXT_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	rectangle(1150, 275, 1800, 450);//khung thong tin sach tra		
	outtextxy(1400, 600, "LAM MAT SACH ?");
	rectangle(1150, 625, w-100, 850);
	setcolor(TIPS);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(1175, 650, "Thu vien se khoa the doc gia cua ban");
	outtextxy(1175, 700, "Sach se chuyen qua trang thai: DA THANH LY");
	outtextxy(1175, 750, "Doc gia can den sach moi co the tiep tuc muon sach");
	outtextxy(1175, 800, "Ban co chac chan xac nhan mat sach ?");
	
	btnXacNhanLamMatSach.draw();
	btnHuyLamMatSach.draw();
}

bool CheckDuplicateISBN_by_MaSach(DS_DauSach &DSDS){
	DauSach *ds;
	if(CurrentDGMT->mt.chuaTra > 0){	
		DSMTS.n = CurrentDGMT->mt.chuaTra;
		int i = DSMTS.n-1;
		for(PTRMT mt = CurrentDGMT->mt.First; mt != NULL; mt = mt->next){
			if(mt->muontra.trangthai == 0){
				ds = GetDauSach(DSDS, mt->muontra.MASACH);
				if (strcmp(ds->ISBN, CurrentDSMT->ISBN)==0)
					return true;
			}
		}
		return false;
	}	
}

void DrawThongTinSach(DS_DauSach &DSDS){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(1095, 300, w, h);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	
	if(CurrentSachMT != NULL){
		setfillstyle(SOLID_FILL, BORDER_COLOR);		
		rectangle(1100, 375, w-100, 625);
		outtextxy(1375, 350, "THONG TIN SACH");
		outtextxy(1150, 400, "Ma sach :");			
		outtextxy(1150, 450, "Ten sach : ");		
		outtextxy(1150, 500, "Trang thai :");	
		outtextxy(1150, 550, "Vi tri :");		
		
		setcolor(TEXT_COLOR_SELECTED);
		outtextxy(1450, 400, CurrentSachMT->MASACH);
		outtextxy(1450, 450, CurrentDSMT->tensach);	
		outtextxy(1450, 500, TrangThaiSach[CurrentSachMT->trangthai]);
		outtextxy(1450, 550, CurrentSachMT->vitri);
		
		if (CheckDuplicateISBN_by_MaSach(DSDS)){
			setcolor(TIPS);
			outtextxy(1130, 600, "THONG BAO : DOC GIA DA MUON SACH THUOC DAU SACH NAY ROI !");
			return;						
		}
		if(CurrentSachMT->trangthai == 0){
			setcolor(TEXT_COLOR_SELECTED);
			outtextxy(1250, 600, "=> DOC GIA CO THE MUON CUON SACH NAY !");
			canMT = true;	// Co the muon sach
		}else if(CurrentSachMT->trangthai == 1){
			setcolor(TIPS);
			outtextxy(1250, 600, "=> DA CO NGUOI MUON CUON SACH NAY !");
			return;
		}else{
			setcolor(TIPS);
			outtextxy(1250, 600, "=> SACH DA THANH LY, KHONG THE MUON !");
			return;
		}
		edNhapNgayMuonSach.draw();
		btnXacNhanMuonSach.draw();
	}else{
		setcolor(TIPS);
		outtextxy(w/2+350, 300, "KHONG TIM THAY SACH!");
	}
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	outtextxy(1175, 840,  mess);
}

void DrawThongTinSachTra(int itemMT){
	if(itemMT != -1){
		CurrentMT = itemMT;		
		setfillstyle(SOLID_FILL, BG_COLOR);			
		bar(250+(w-250)/2+5, 240, w, h);
				
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);				
		outtextxy(1375, 250, "THONG TIN SACH");
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setcolor(TEXT_COLOR);	
		rectangle(1150, 275, 1800, 450);//khung thong tin sach tra		
		outtextxy(1250, 300, "Ma sach :");					
		outtextxy(1250, 350, "Ten sach : ");		
		outtextxy(1250, 400, "Ngay muon :");
		
		setcolor(TEXT_COLOR_SELECTED);		
		outtextxy(1500, 300, DSMTS.mt[CurrentMT].MASACH);
		outtextxy(1500, 350, DSMTS.mt[CurrentMT].TenSach);	
		outtextxy(1500, 400, DSMTS.mt[CurrentMT].NgayMuon);	
			
		if(subWindow == XAC_NHAN_TRA_SACH){
			edNhapNgayTraSach.draw();
			btnXacNhanTraSach.draw();
			btnLamMatSach.draw();		
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			setcolor(TIPS);
			outtextxy(1200, 650,  mess);			
		}else if(subWindow == XAC_NHAN_LAM_MAT_SACH)
			DrawLamMatSach();
	}
}

void MuonTraEvent(DS_DauSach &DSDS, TreeDocgia &DSDG){
	char confirm[50];
	ButtonEffect(btnBackToMenu);
	ButtonEffect(btnMuonSach);
	ButtonEffect(btnTraSach);
	ButtonEffect(btnTopTen);
	if(GetAsyncKeyState(VK_LBUTTON)){
		memset(mess, 0, sizeof(mess));
		if(btnBackToMenu.isMouseHover(mx, my))
			SetMenuSelect(DSDS, DSDG, 0);	
		else if(btnMuonSach.isMouseHover(mx, my) && (Window != MUON_SACH)){
			Window = MUON_SACH;
			DrawTrangConDSMT(DSDS);
			if(CurrentDGMT!=NULL){
				CurrentDGMT = &TimDocGiaTheoMa(root, CurrentDGMT->MATHE)->docgia;
				DrawThongTinDocGia(DSDS, DSDG);					
			}
		}else if(btnTraSach.isMouseHover(mx, my) && (Window != TRA_SACH)){
			Window = TRA_SACH;
			DrawTrangConDSMT(DSDS);
			if(CurrentDGMT!=NULL){
				CurrentDGMT = &TimDocGiaTheoMa(root, CurrentDGMT->MATHE)->docgia;
				DrawThongTinDocGia(DSDS, DSDG);					
			}
		}else if(btnTopTen.isMouseHover(mx, my) && (Window != TOP_TEN)){
			Window = TOP_TEN;
			DrawTrangConDSMT(DSDS);
		}
	}
	if(Window == MUON_SACH){
		ButtonEffect(btnTimMaDG);	
		ButtonEffect(btnTraNgay);	
		subWindow = CONFIRM_POPUP_NONE;
		if(GetAsyncKeyState(VK_LBUTTON)){
			if(edNhapMaDGMuonSach.isMouseHover(mx, my))
				Edit = &edNhapMaDGMuonSach;
			else if(btnTimMaDG.isMouseHover(mx, my)){
				CurrentDGMT = &TimDocGiaTheoMa(root, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia(DSDS, DSDG);
			}	
			else if (btnTraNgay.isMouseHover(mx, my) && CurrentDGMT != NULL){			
				Window = TRA_SACH;
				DrawTrangConDSMT(DSDS);
				CurrentDGMT = &TimDocGiaTheoMa(root, CurrentDGMT->MATHE)->docgia;
				DrawThongTinDocGia(DSDS, DSDG);		
			}				
		}
		if(canBorrow && CurrentDGMT != NULL){
			ButtonEffect(btnTimMaSach);
			if(canMT) ButtonEffect(btnXacNhanMuonSach);
			
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(edNhapMaSachMuonSach.isMouseHover(mx, my))
					Edit = &edNhapMaSachMuonSach;
				else if(btnTimMaSach.isMouseHover(mx, my)){
					if(strlen(edNhapMaSachMuonSach.content) > 0){
						// tim Dau Sach co chua Ma Sach can tim
						CurrentDSMT = GetDauSach(DSDS, edNhapMaSachMuonSach.content);
						if(CurrentDSMT == NULL)	CurrentSachMT = NULL;
						else
							for(SachPTR node = CurrentDSMT->First; node != NULL; node = node->next)
									if(strcmp(node->sach.MASACH, edNhapMaSachMuonSach.content) == 0) 
										CurrentSachMT = &node->sach;									
						strcpy(edNhapNgayMuonSach.content, GetSystemDate());
						DrawThongTinSach(DSDS);
					}
				}
				else if(edNhapMaSachMuonSach.isMouseHover(mx, my))
					Edit = &edNhapMaSachMuonSach;	
				else if(CurrentSachMT != NULL && canMT){				
					if(btnXacNhanMuonSach.isMouseHover(mx, my)){
						if(!CheckDate(edNhapNgayMuonSach.content)){
							strcpy(mess, "THONG BAO : DINH DANG KHONG HOP LE (VD: 25/11/2022)");
							DrawThongTinSach(DSDS);
						}
						else{							
							// 0: DANG MUON
							MuonTra muon(CurrentSachMT->MASACH, edNhapNgayMuonSach.content, "", 0);
							InsertLast_MuonTra(CurrentDGMT->mt, muon);							
							SachPTR nodeSach = GetNodeSachByMASACH(CurrentDSMT->First, CurrentSachMT->MASACH);
							Sach sach = nodeSach->sach;
							sach.trangthai = 1; 	// DA CHO MUON
							UpdateNodeSach(nodeSach, sach);							
							// Tang so luot muon sach cua Dau Sach
							CurrentDSMT->soluotmuon ++;		
							CurrentDSMT = NULL;		
							CurrentSachMT = NULL;	
							canMT = false;							
							DrawThongTinDocGia(DSDS, DSDG);									
						}
					}
				}	
			}
		}
	}
	else if(Window == TRA_SACH){	
		ButtonEffect(btnTimMaDG);
		ButtonEffect(btnTraSach);
		ItemSachMuonEvent();
		ButtonEffect(btnMuonNgay);
		if(GetAsyncKeyState(VK_LBUTTON)){
			if(edNhapMaDGMuonSach.isMouseHover(mx, my))
				Edit = &edNhapMaDGMuonSach;
			else if(btnTimMaDG.isMouseHover(mx, my)){
				CurrentDGMT = &TimDocGiaTheoMa(root, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia(DSDS, DSDG);
			}
			else if(CurrentItemMT != -1){
				subWindow = XAC_NHAN_TRA_SACH;
				strcpy(edNhapNgayTraSach.content, GetSystemDate());
				DrawThongTinSachTra(CurrentItemMT);
			}
			else if (btnMuonNgay.isMouseHover(mx, my) && CurrentDGMT != NULL){			
				Window = MUON_SACH;
				DrawTrangConDSMT(DSDS);
				CurrentDGMT = &TimDocGiaTheoMa(root, CurrentDGMT->MATHE)->docgia;
				DrawThongTinDocGia(DSDS, DSDG);		
			}			
		}			
		if(subWindow == XAC_NHAN_TRA_SACH){
			ButtonEffect(btnXacNhanTraSach);
			ButtonEffect(btnLamMatSach);
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(CurrentMT != -1 && CurrentDGMT != NULL){
					if(btnXacNhanTraSach.isMouseHover(mx, my)){
						if(!CheckDate(edNhapNgayTraSach.content)){
							strcpy(mess, "THONG BAO : Ngay nhap vao khong hop le");
							DrawThongTinSachTra(CurrentMT);
						}else{
							//DA TRA 
							MuonTra tra(DSMTS.mt[CurrentMT].MASACH, DSMTS.mt[CurrentMT].NgayMuon, edNhapNgayTraSach.content, 1);
							Update_MuonTra(CurrentDGMT->mt, tra);							
							CurrentDSMT = GetDauSach(DSDS, DSMTS.mt[CurrentMT].MASACH);							
							SachPTR nodeSach = GetNodeSachByMASACH(CurrentDSMT->First, DSMTS.mt[CurrentMT].MASACH);
							Sach sach = nodeSach->sach;
							sach.trangthai = 0; 	// CHO MUON DUOC
							UpdateNodeSach(nodeSach, sach);		
							if(!isDGQH(DSDS, DSDG))
								CurrentDGMT->trangthai = 1; // MO KHOA THE DOC GIA	
			
							CurrentDSMT = NULL;		CurrentMT = -1;							
							memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
							subWindow = TRANG_NULL;
							DrawThongTinDocGia(DSDS, DSDG);
						}					
					}
					else if(btnLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_LAM_MAT_SACH;
						DrawThongTinSachTra(CurrentMT);
					}	
				}
			}
		}
		else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
			ButtonEffect(btnXacNhanLamMatSach);
			ButtonEffect(btnHuyLamMatSach);
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(CurrentMT != -1 && CurrentDGMT != NULL){
					if(btnXacNhanLamMatSach.isMouseHover(mx, my)){
						MuonTra tra(DSMTS.mt[CurrentMT].MASACH, DSMTS.mt[CurrentMT].NgayMuon, "", 2);
						Update_MuonTra(CurrentDGMT->mt, tra);							
						CurrentDSMT = GetDauSach(DSDS, DSMTS.mt[CurrentMT].MASACH);							
						SachPTR nodeSach = GetNodeSachByMASACH(CurrentDSMT->First, DSMTS.mt[CurrentMT].MASACH);
						Sach sach = nodeSach->sach;
						sach.trangthai = 2; 	// DA THANH LY
						UpdateNodeSach(nodeSach, sach);								
						CurrentDSMT = NULL; CurrentMT = -1;						
						CurrentDGMT->trangthai = 0; // KHOA THE DOC GIA
						UpdateDocGia(root, *CurrentDGMT);								
						memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
						subWindow = TRANG_NULL;
						DrawThongTinDocGia(DSDS, DSDG);
					}
					else if(btnHuyLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_TRA_SACH;
						DrawThongTinSachTra(CurrentMT);
					}					
				}
			}
		}
		else if(subWindow == TRANG_NULL){
			
		}
	}
}
 
void DrawMuonSach(){
	CurrentMenuMuonTra = -1;
	btnMuonSach.isHover = true;
	btnMuonSach.isChoose = true;
	btnBackToMenu.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy(w/2-textwidth(DauSachTitle)/2, 15, MuonSach);
	
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
}












