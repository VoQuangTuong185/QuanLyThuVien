void AutoGenMaDocGia(){
	nodeStart = Node_ID_Random();
	if(nodeStart != NULL){
		int ranID = rand()%(nodeStart->next->id - nodeStart->id - 1) + nodeStart->id + 1;
		itoa(ranID, edThemMaTheDocGia.content, 10);
	}else
		strcpy(edThemMaTheDocGia.content, "OVERFLOW");	
}

int GetItemDocGiaPosition(TreeDocgia &DSDG, int y){
	int pos = (y-220+8)/40;
	int i;
	if(btnTatCaDocGia.isChoose){
		i = 13*(curPageDG-1) + pos;
	}else{
		i = 13*(curPageDGQuaHan-1) + pos;
	}
	if(i >= DSDG.n) return -1;
	return pos;
}

void GetHieuChinhDocGia(TreeDocgia &DSDG, int i){
	curDG = i;
	ClearScreen(7);//clear content
	
	char ch[10];
	itoa(DSDG.nodes[i]->MATHE, ch, 10);
	strcpy(edHieuChinhMaTheDocGia.content, ch);
	strcpy(edHieuChinhHoDocGia.content, DSDG.nodes[i]->ho);
	strcpy(edHieuChinhTenDocGia.content, DSDG.nodes[i]->ten);
	itoa(DSDG.nodes[i]->phai, ch, 10);
	strcpy(edHieuChinhPhaiDocGia.content, ch);
	itoa(DSDG.nodes[i]->trangthai, ch, 10);
	strcpy(edHieuChinhTrangThaiTheDocGia.content, ch);
	// Clear
	DrawHieuChinhDocGia();
}

void ButtonSwitchClick(TreeDocgia &DSDG){
	if(btnTatCaDocGia.isMouseHover(mx, my)){
		if(!btnTatCaDocGia.isChoose){
			ClearScreen(9);
			btnDocGiaQuaHan.isChoose = false;
			btnTatCaDocGia.isChoose = true;
			curItemDG = -1;
			
			DrawListDocGia(DSDG, true);
			DrawDanhSachDocGia(DSDG);
		
			btnSapXepTen.isChoose = sortDGByName;
			btnSapXepMaThe.isChoose = !btnSapXepTen.isChoose; 
			
			btnSapXepTen.isHover = sortDGByName;
			btnSapXepMaThe.isHover = !sortDGByName;		
			btnSapXepTen.draw();
			btnSapXepMaThe.draw();
		}
	}else if(btnDocGiaQuaHan.isMouseHover(mx, my)){
		if(!btnDocGiaQuaHan.isChoose){
			ClearScreen(8);

			btnTatCaDocGia.isChoose = false;
			btnDocGiaQuaHan.isChoose = true;
			curItemDG = -1;
			// Get list docgia qua han			
			DSDG.GetDocGiaQuaHan(root);
			DrawListDocGia(DSDG);
		}
	}
	
	if(btnSapXepTen.isMouseHover(mx, my)){
		if(!sortDGByName){
			sortDGByName = true;
			ClearScreen(8);

			DrawListDocGia(DSDG);
		}
	}else if(btnSapXepMaThe.isMouseHover(mx, my)){
		if(sortDGByName){
			sortDGByName = false;
			ClearScreen(8);

			DrawListDocGia(DSDG);
		}
	}
	btnSapXepTen.isChoose = sortDGByName;
	btnSapXepMaThe.isChoose = !sortDGByName;
}

void ItemDocGiaEvent(TreeDocgia &DSDG){
	if(mx > XXXDG[0] && mx < XXXDG[btnTatCaDocGia.isChoose?5:6] && my > 220-8 && my < 220+13*40-8){		
		if(curItemDG != GetItemDocGiaPosition(DSDG, my)){
			if(curItemDG != -1){
				// khoi phuc item
				setfillstyle(SOLID_FILL, BG_COLOR);
				bar(XXXDG[0], 220 + curItemDG*40 - 8, XXXDG[btnTatCaDocGia.isChoose?5:6], 220+(curItemDG+1)*40-8);
				
				setbkcolor(BG_COLOR);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setcolor(TEXT_COLOR);
				
				if(btnTatCaDocGia.isChoose){
					DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, false);
					DrawBorderDSDocGia();
				}
				else{
					DrawItemDocGia(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, true);
					DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
					DrawBorderDSDocGiaQuaHan();
				}							
			}	
			// Ve item hien tai
			curItemDG = GetItemDocGiaPosition(DSDG, my);
			if(curItemDG != -1){
				setfillstyle(SOLID_FILL, LINE);
				bar(XXXDG[0], 220 + curItemDG*40 - 8, XXXDG[btnTatCaDocGia.isChoose?5:6], 220+(curItemDG+1)*40-8);
				
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setbkcolor(LINE);
				setcolor(TEXT_COLOR);
				
				if(btnTatCaDocGia.isChoose){
					DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, false);
					DrawBorderDSDocGia();
				}
				else{
					DrawItemDocGia(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, true);
					DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
					DrawBorderDSDocGiaQuaHan();
				}
			}
		}
	}else{
		if(curItemDG != -1){
			// khoi phuc item
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XXXQH[0], 220 + curItemDG*40 - 8, XXXQH[btnTatCaDocGia.isChoose?5:6], 220+(curItemDG+1)*40-8);
			setbkcolor(BG_COLOR);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
			setcolor(TEXT_COLOR);
			
			if(btnTatCaDocGia.isChoose){
				DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, false);
				DrawBorderDSDocGia();
			}
			else{
				DrawItemDocGia(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG, true);
				DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
				DrawBorderDSDocGiaQuaHan();
			}			
			curItemDG = -1;
		}
	}
}

void DrawDanhSachDocGia(TreeDocgia &DSDG){
	ClearScreen(1);
	strcpy(mess, " ");
	
	btnSapXepTen.isChoose = sortDGByName;
	btnSapXepMaThe.isChoose = !btnSapXepTen.isChoose; 
	
	btnSapXepTen.isHover = sortDGByName;
	btnSapXepMaThe.isHover = !sortDGByName;
	
	btnSapXepTen.draw();
	btnSapXepMaThe.draw();
	
	btnTatCaDocGia.isHover = true;
	btnTatCaDocGia.isChoose = true;
	btnDocGiaQuaHan.isChoose = false;
	btnDocGiaQuaHan.isHover = false;
	
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	
	DrawListDocGia(DSDG, true);	
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy(w/2-textwidth(DocGiaTitle)/2, 15, DocGiaTitle);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	outtextxy(XXXDG[0], 100, "Sap xep theo:");
	
	btnQuayVeMenu.draw();
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	btnPrev.draw();
	btnNext.draw();
	btnSapXepTen.draw();
	btnSapXepMaThe.draw();
}

void DrawBorderDSDocGia(){		
	char ch[6][20] = {"Ma the", "Ho", "Ten", "Phai", "Trang thai the"};
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	
	bar(XXX[0], 152, w-200, 215);	
	
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 5; i++)
		outtextxy(XXXDG[i] + (XXXDG[i+1]-XXXDG[i])/2 - textwidth(ch[i])/2, 170, ch[i]);
	
	setbkcolor(BG_COLOR);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(BORDER_COLOR);
	rectangle(XXXDG[0], 150, XXXDG[5], 750);
	line(XXXDG[0], 150 + 25 + 2*20, XXXDG[5], 150 + 25 + 2*20);
	for(int i=0; i < 5; i++)
		line(XXXDG[i], 150, XXXDG[i], 750);
}

void DrawBorderDSDocGiaQuaHan(){
	char ch[7][20] = {"Ma the", "Ho", "Ten", "Phai", "Trang thai the", "So ngay qua han"};
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	
	bar(XXX[0], 152, w-200, 215);		
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 6; i++)
		outtextxy(XXXQH[i] + (XXXQH[i+1]-XXXQH[i])/2 - textwidth(ch[i])/2, 170, ch[i]);
	
	setbkcolor(BG_COLOR);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(BORDER_COLOR);
	rectangle(XXXQH[0], 150, XXXQH[6], 750);
	line(XXXQH[0], 150 + 25 + 2*20, XXXQH[6], 150 + 25 + 2*20);
	for(int i=0; i < 6; i++)
		line(XXXQH[i], 150, XXXQH[i], 750);
}
 
void DrawListDocGia(TreeDocgia &DSDG, bool reload){
	char chPage[20];
	
	if(reload && btnTatCaDocGia.isChoose) 
		DSDG.GetAllDocGia(root);
	
	if(btnTatCaDocGia.isChoose){
		DrawBorderDSDocGia();	
		if(sortDGByName)
			DSDG.SapXepDocGia(MODE_TEN);
		else
			DSDG.SapXepDocGia(MODE_MA_THE);	
		totalPageDG = (DSDG.n-1)/13 + 1;
		for(int i=13*(curPageDG-1); i < 13*curPageDG; i++){
			if(i >= DSDG.n) break;
			DrawItemDocGia(*DSDG.nodes[i], i, false);
		}	
		// num page		
		sprintf(chPage, "TRANG %d / %d", curPageDG, totalPageDG);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy(w/2 - textwidth(chPage)/2, 785, chPage);
		
		btnPrev.draw();
		btnNext.draw();
		btnThemMaThe.draw();
	}
	else if(btnDocGiaQuaHan.isChoose){
		DrawBorderDSDocGiaQuaHan();	
		totalPageDGQuaHan = (DSDG.n-1)/13 + 1;
		for(int i=13*(curPageDGQuaHan-1); i < 13*curPageDGQuaHan; i++){
			if(i >= DSDG.n) break;
			DrawItemDocGia(*DSDG.nodes[i], i, true);
			DrawItemDocGiaQuaHan(*DSDG.nodes[i], DSDG.soNgayQH[i], i);
		}		
		// num page
		sprintf(chPage, "TRANG %d / %d", curPageDGQuaHan, totalPageDGQuaHan);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy(w/2 - textwidth(chPage)/2, 785, chPage);		
		btnPrevDocGiaQH.draw();
		btnNextDocGiaQH.draw();
	}	
	setcolor(TEXT_COLOR);
	rectangle((w/2)-250, 850, (w/2)+250 , 950);
	outtextxy((w/2)-230, 865, "Click chuot trai: Hieu chinh doc gia");
	outtextxy((w/2)-230, 915, "Click chuot phai: Xoa doc gia");
}

void DrawThemDocGia(bool genNewID){
	ClearScreen(1);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2)-400, 210, (w/2)+400, 280);
	
	//dinh dang tieu de khung THEM THE DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2)-400, 210, (w/2)+400, 700);
	line((w/2)-400, 280, (w/2)+400, 280);
	line((w/2)-400, 650, (w/2)+400, 650);

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(ThemDocGia)/2, 245 - textheight(ThemDocGia)/2, ThemDocGia);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XXX[7]-30, 675-textheight(ThongBao)/2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);		bar((w/2)-390 + textwidth(ThongBao), 675-textheight(ThongBao)/2, (w/2)+390, 675+textheight(ThongBao)/2);
	setcolor(TIPS);							outtextxy(XXX[7]-10 + textwidth(ThongBao), 675-textheight(ThongBao)/2, mess);
	
	if(genNewID) 
		AutoGenMaDocGia();
		
	strcpy(edThemTrangThaiTheDocGia.content, "1");
	
	edThemMaTheDocGia.draw();
	edThemHoDocGia.draw();
	edThemTenDocGia.draw();
	edThemPhaiDocGia.draw();
	edThemTrangThaiTheDocGia.draw();	
	btnThemDocGia.draw();
	btnClearFormDocGia.draw();
	btnBack.draw();
} 

void DrawHieuChinhDocGia(){
	ClearScreen(1);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2)-400, 210, (w/2)+400, 280);
	
	//dinh dang tieu de khung THEM THE DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2)-400, 210, (w/2)+400, 700);
	line((w/2)-400, 280, (w/2)+400, 280);
	line((w/2)-400, 650, (w/2)+400, 650);

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(HieuChinhDocGia)/2, 245 - textheight(HieuChinhDocGia)/2, HieuChinhDocGia);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XXX[7]-30, 675-textheight(ThongBao)/2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w/2)-390 + textwidth(ThongBao), 675-textheight(ThongBao)/2, (w/2)+390, 675+textheight(ThongBao)/2);

	setcolor(TIPS);
	outtextxy(XXX[7]-10 + textwidth(ThongBao), 675-textheight(ThongBao)/2, mess);
	
	edHieuChinhMaTheDocGia.draw();
	edHieuChinhHoDocGia.draw();
	edHieuChinhTenDocGia.draw();
	edHieuChinhPhaiDocGia.draw();
	edHieuChinhTrangThaiTheDocGia.draw();
	
	btnHieuChinhDocGia.draw();
	btnClearFormDocGia.draw();
	btnBack.draw();
} 

void DrawItemDocGiaQuaHan(DocGia &docgia, int soNgayQH, int i){
	DrawItemDocGia(docgia, i, true);
	char ch[4];
	sprintf(ch, "%d", soNgayQH);
	outtextxy(XXXQH[5]+50, 220 + i*40, ch);
}

void DrawItemDocGia(DocGia &docgia, int i, bool QUAHAN){
	setcolor(TEXT_COLOR);
	i %= 13;
	char ch[6];
	itoa(docgia.MATHE, ch, 10);
	if(QUAHAN){
		outtextxy((XXXQH[0] + XXXQH[1])/2 - textwidth(ch)/2, 220 + i*40, ch);
		outtextxy(XXXQH[1] + 10, 220 + i*40, docgia.ho);
		outtextxy(XXXQH[2] + 10, 220 + i*40, docgia.ten);
		outtextxy(XXXQH[3] + 30, 220 + i*40, PhaiDocGia[docgia.phai]);
		outtextxy((XXXQH[4] + XXXQH[5])/2 - textwidth(TTTDocGia[docgia.trangthai])/2, 220 + i*40, TTTDocGia[docgia.trangthai]);			
	}
	else {
		outtextxy((XXXDG[0] + XXXDG[1])/2 - textwidth(ch)/2, 220 + i*40, ch);
		outtextxy(XXXDG[1] + 10, 220 + i*40, docgia.ho);
		outtextxy(XXXDG[2] + 10, 220 + i*40, docgia.ten);
		outtextxy(XXXDG[3] + 30, 220 + i*40, PhaiDocGia[docgia.phai]);
		outtextxy((XXXDG[4] + XXXDG[5])/2 - textwidth(TTTDocGia[docgia.trangthai])/2, 220 + i*40, TTTDocGia[docgia.trangthai]);	
	}
}

void DrawXoaDocGia(TreeDocgia &DSDG, int i){
	ClearScreen(1);	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2)-400, 210, (w/2)+400, 280);	
	//dinh dang tieu de khung THEM THE DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2)-400, 210, (w/2)+400, 700);
	line((w/2)-400, 280, (w/2)+400, 280);
	line((w/2)-400, 650, (w/2)+400, 650);

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(XoaDocGia)/2, 245 - textheight(XoaDocGia)/2, XoaDocGia);
	
	setbkcolor(BG_COLOR);
	if(i != -1){
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
		setcolor(TEXT_COLOR);
		curDG = i;		
		char ch[50];
		sprintf(ch, "%s %s", DSDG.nodes[i]->ho, DSDG.nodes[i]->ten);
		outtextxy(XXX[7], 300, "Doc gia :");				outtextxy(XXX[7]+450, 300, ch);		
		outtextxy(XXX[7], 350, "Ma the :");					itoa(DSDG.nodes[i]->MATHE, ch, 10);				outtextxy(XXX[7]+450, 350, ch);	
		outtextxy(XXX[7], 400, "Phai :");					outtextxy(XXX[7]+450, 400, PhaiDocGia[DSDG.nodes[i]->phai]);		
		outtextxy(XXX[7], 450, "Trang thai the :");			outtextxy(XXX[7]+450, 450, TTTDocGia[DSDG.nodes[i]->trangthai]);		
		outtextxy(XXX[7], 500, "So sach dang muon :");		itoa(DSDG.nodes[i]->mt.chuaTra, ch, 10);		outtextxy(XXX[7]+450, 500, ch);		
		outtextxy(XXX[7], 550, "Tong so sach da muon :");	itoa(DSDG.nodes[i]->mt.total, ch, 10);			outtextxy(XXX[7]+450, 550, ch);	
		btnXacNhanXoaDocGia.draw();
	}
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);		setcolor(TEXT_COLOR);		outtextxy(XXX[7]-30, 675-textheight(ThongBao)/2, ThongBao);
	setfillstyle(SOLID_FILL, BG_COLOR);			bar((w/2)-390 + textwidth(ThongBao), 675-textheight(ThongBao)/2, (w/2)+390, 675+textheight(ThongBao)/2);
	setcolor(TIPS);								outtextxy(XXX[7]-10 + textwidth(ThongBao), 675-textheight(ThongBao)/2, mess);		
	btnBack.draw();
}

void DrawTrangConDSDG(TreeDocgia &DSDG){
	if(Window == DANH_SACH_DOC_GIA)
		DrawDanhSachDocGia(DSDG);
	else if(Window == THEM_DOC_GIA)
		DrawThemDocGia();
	else if(Window == HIEU_CHINH_DOC_GIA){
		DrawHieuChinhDocGia();
		if(btnTatCaDocGia.isChoose)
			GetHieuChinhDocGia(DSDG, 13*(curPageDG-1) + curItemDG);
		else
			GetHieuChinhDocGia(DSDG, 13*(curPageDGQuaHan-1) + curItemDG);
	}
	else if(Window == XOA_DOC_GIA){
		if(btnTatCaDocGia.isChoose)
			DrawXoaDocGia(DSDG, 13*(curPageDG-1) + curItemDG);
		else
			DrawXoaDocGia(DSDG, 13*(curPageDGQuaHan-1) + curItemDG);		
	}
}

void DocGiaEvent(DS_DauSach &DSDS, TreeDocgia &DSDG){
	char confirm[50];	
	ButtonEffect(btnQuayVeMenu);
	ButtonEffect(btnTatCaDocGia);
	ButtonEffect(btnDocGiaQuaHan);
	if (Window == DANH_SACH_DOC_GIA){
		ItemDocGiaEvent(DSDG);
		ButtonEffect(btnPrev);
		ButtonEffect(btnNext);
		if(GetAsyncKeyState(VK_LBUTTON)){
			ButtonSwitchClick(DSDG);
			if(btnQuayVeMenu.isMouseHover(mx, my))
				SetMenuSelect(DSDS, DSDG, 0);			
		}	
		if(btnTatCaDocGia.isChoose){
			ButtonEffect(btnSapXepTen);
			ButtonEffect(btnSapXepMaThe);
			ButtonEffect(btnThemMaThe);
			if(GetAsyncKeyState(VK_LBUTTON)){ //chuot trai				
				if(btnThemMaThe.isMouseHover(mx, my)){
					Window = THEM_DOC_GIA;
					DrawTrangConDSDG(DSDG);	
				} 
				else if(curItemDG != -1){
					strcpy(mess, "");
					Window = HIEU_CHINH_DOC_GIA;
					DrawTrangConDSDG(DSDG);	
				}
				// Tat ca Doc gia - MODE		
				else if(btnPrev.isMouseHover(mx, my)){
					if(curPageDG > 1){
						ClearScreen(8);
						curPageDG--;
						DrawListDocGia(DSDG);
					}
				}else if(btnNext.isMouseHover(mx, my)){
					if(curPageDG < totalPageDG){
						ClearScreen(8);
						curPageDG ++;
						DrawListDocGia(DSDG);
					}
				} 
			}
			else if(GetAsyncKeyState(VK_RBUTTON)){//chuot phai
				if(curItemDG != -1){
					strcpy(mess, "");
					Window = XOA_DOC_GIA;
					subWindow = CONFIRM_POPUP_NONE;
					DrawTrangConDSDG(DSDG);	
				}			
			}
		}else if (btnDocGiaQuaHan.isChoose){ 
			ButtonEffect(btnPrevDocGiaQH);
			ButtonEffect(btnNextDocGiaQH);
			if(GetAsyncKeyState(VK_LBUTTON)){
				// Doc Gia Qua Han - MODE
				if(curItemDG != -1){
					strcpy(mess, "");
					Window = HIEU_CHINH_DOC_GIA;
					DrawTrangConDSDG(DSDG);	
				}
				else if(btnPrevDocGiaQH.isMouseHover(mx, my)){
					if(curPageDGQuaHan > 1){
						curPageDGQuaHan--;
						ClearScreen(9);
						DrawListDocGia(DSDG);
					}
				}else if(btnNextDocGiaQH.isMouseHover(mx, my)){
					if(curPageDGQuaHan < totalPageDGQuaHan){
						curPageDGQuaHan ++;
						ClearScreen(9);
						DrawListDocGia(DSDG);
					}
				}				
			}
			else if(GetAsyncKeyState(VK_RBUTTON)){//chuot phai
				if(curItemDG != -1){
					strcpy(mess, "");
					Window = XOA_DOC_GIA;
					subWindow = CONFIRM_POPUP_NONE;
					DrawTrangConDSDG(DSDG);	
				}			
			}
		}				
	}			
	else if(Window == THEM_DOC_GIA){
		ButtonEffect(btnThemDocGia);
		ButtonEffect(btnClearFormDocGia);
		if(GetAsyncKeyState(VK_LBUTTON)){	
			if(btnQuayVeMenu.isMouseHover(mx, my)){//back to DSDG
				ClearScreen(6); //clear content
				Window = DANH_SACH_DOC_GIA;	
				DrawTrangConDSDG(DSDG);
			}
			else if(btnThemDocGia.isMouseHover(mx, my)){
				if(CheckDocGia(edThemMaTheDocGia, edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia, true)){
					DocGia docgia(edThemMaTheDocGia.toInt(), 
								edThemHoDocGia.trim(), 
								edThemTenDocGia.trim(), 
								edThemPhaiDocGia.toInt(), 
								edThemTrangThaiTheDocGia.toInt());	
															
					InsertDocGia(root, docgia);
					insertAfter_ID(nodeStart, edThemMaTheDocGia.toInt());			
					strcpy(mess, "Them doc gia thanh cong!");
					ClearScreen(5);
					DrawListDocGia(DSDG, true);
					DrawThemDocGia();
				}else
					DrawThemDocGia(false);					
			}				
			else if(edThemHoDocGia.isMouseHover(mx, my))
				Edit = &edThemHoDocGia;
			else if(edThemTenDocGia.isMouseHover(mx, my))
				Edit = &edThemTenDocGia;
			else if(edThemPhaiDocGia.isMouseHover(mx, my))
				Edit = &edThemPhaiDocGia;
			else if(edThemTrangThaiTheDocGia.isMouseHover(mx, my))
				Edit = &edThemTrangThaiTheDocGia;					
		}
	}else if(Window == HIEU_CHINH_DOC_GIA){
		ButtonEffect(btnHieuChinhDocGia);
		ButtonEffect(btnClearFormDocGia);
		ButtonEffect(btnBack);
		if(GetAsyncKeyState(VK_LBUTTON)){
			if(btnBack.isMouseHover(mx, my)){
				strcpy(mess, "");
				ClearScreen(7);
				Window = DANH_SACH_DOC_GIA;	
				DrawTrangConDSDG(DSDG);
			}
			else if(btnHieuChinhDocGia.isMouseHover(mx, my)){
				if(curDG != -1 && CheckDocGia(edHieuChinhMaTheDocGia, edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia, false)){
					DocGia docgia(edHieuChinhMaTheDocGia.toInt(), 
									edHieuChinhHoDocGia.trim(), 
									edHieuChinhTenDocGia.trim(), 
									edHieuChinhPhaiDocGia.toInt(), 
									edHieuChinhTrangThaiTheDocGia.toInt());
					UpdateDocGia(root, docgia);
					strcpy(mess, "Hieu chinh doc gia thanh cong!");
					ClearScreen(8);

					DrawListDocGia(DSDG, true);
					curDG = -1;
				}
				DrawHieuChinhDocGia();
			}				
			else if(curDG != -1){
				if(edHieuChinhHoDocGia.isMouseHover(mx, my))
					Edit = &edHieuChinhHoDocGia;
				else if(edHieuChinhTenDocGia.isMouseHover(mx, my))
					Edit = &edHieuChinhTenDocGia;
				else if(edHieuChinhPhaiDocGia.isMouseHover(mx, my))
					Edit = &edHieuChinhPhaiDocGia;
				else if(edHieuChinhTrangThaiTheDocGia.isMouseHover(mx, my))
					Edit = &edHieuChinhTrangThaiTheDocGia;			
			}			
		}
	}else if(Window == XOA_DOC_GIA){
		if(subWindow == CONFIRM_POPUP_NONE){
			ButtonEffect(btnBack);
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(btnBack.isMouseHover(mx, my)){
					strcpy(mess, "");
					Window = DANH_SACH_DOC_GIA;	
					DrawTrangConDSDG(DSDG);
				}	
				else if(btnXacNhanXoaDocGia.isMouseHover(mx, my) && curDG != -1){
					// neu doc gia k muon sach nao thi co the xoa
					if(DSDG.nodes[curDG]->mt.total == 0){
						strcpy(confirm, "XAC NHAN XOA MA THE DOC GIA NAY?");
						Edit = NULL;
						subWindow = CONFIRM_POPUP;
						PopUp(confirm);	
					}else{
						// Doc gia dang muon sach -> k the xoa
						strcpy(mess, "Doc gia da muon sach nen khong the xoa!");
						DrawXoaDocGia(DSDG, curDG);
					}
				}			
			}
			else if(curDG != -1)
				ButtonEffect(btnXacNhanXoaDocGia);			
		}
		else if(subWindow == CONFIRM_POPUP){
			ButtonEffect(btnYes);
			ButtonEffect(btnNo);
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(btnYes.isMouseHover(mx, my)){
					if(delete_ID(DSDG.nodes[curDG]->MATHE)){
						RemoveDocGia(root, DSDG.nodes[curDG]->MATHE);
						strcpy(mess, "Xoa doc gia thanh cong!");
						DrawXoaDocGia(DSDG, curDG);	
						delay(2000);
						curDG = -1;
						Window = DANH_SACH_DOC_GIA;
						subWindow = CONFIRM_POPUP_NONE;
						DrawTrangConDSDG(DSDG);														
					}
				}
				else if (btnNo.isMouseHover(mx, my)){
					subWindow = CONFIRM_POPUP_NONE;
					DrawXoaDocGia(DSDG, curDG);	
				}							
			}
		}
	}
}

bool CheckDocGia(EditText &MaThe, EditText &Ho, EditText &Ten, EditText &Phai, EditText &TrangThai, bool them){
	if((strcmp(MaThe.content, "OVERFLOW") == 0) && (them)){
		strcpy(mess, "So luong doc gia dat gioi han");
		return false;
	}	
	if(strlen(Ho.content) == 0){
		strcpy(mess, "Ho va ten dem khong duoc bo trong");
		Edit = &edThemHoDocGia;
		Edit->draw();
		return false;
	}else if(strlen(Ten.content) == 0){
		strcpy(mess, "Ten khong duoc bo trong");
		Edit = &edThemTenDocGia;
		Edit->draw();
		return false;
	}else if(strlen(Phai.content) == 0){
		strcpy(mess, "Phai khong duoc bo trong");
		Edit = &edThemPhaiDocGia;
		Edit->draw();
		return false;
	}else if(strlen(TrangThai.content) == 0){
		strcpy(mess, "Trang thai the khong duoc bo trong");
		Edit = &edThemTrangThaiTheDocGia;
		Edit->draw();
		return false;
	}
	return true;
}










