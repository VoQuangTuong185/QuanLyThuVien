// lay max width, height cua man hinh
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

//////////////////////////////////////////KHU TU TRI CUA DAU SACH VA DANH MUC SACH /////////////////////////////////////////////////
EditText *Edit = NULL;
// hoanh do x cua Dau Sach de ve cot
int XXX[8] = {200, 380, 900, 1050, 1400, 1500, w-200, 600}; //phan tu cuoi cung la vi tri cac edit box
// X Danh Muc Sach
int XDMS[4] = {(w/2)-450, (w/2)-250, (w/2)+100, (w/2)+450};

char mess[50];
char *TrangThaiSach[15] = {"CHO MUON DUOC", "DA CHO MUON", "DA THANH LY"};
char thongBao[50];

char AppTitle[] = "Phan Mem Quan Ly Thu Vien";
char DauSachTitle[] = "DANH SACH DAU SACH";
char ThemDauSach[] = "THEM DAU SACH";
char ThongBao[] = "THONG BAO:";
char HieuChinhDauSach[] = "HIEU CHINH DAU SACH";
char DanhMucSach[80] = "DANH MUC SACH: ";
char NhapSach[] = "NHAP SACH";
char HieuChinhSach[] = "HIEU CHINH SACH";
char ThemSach[] = "THEM SACH: ";

Button btnQLDauSach(100, w/2-325, 200 + 80, 300, 200, "QUAN LY DAU SACH", 0);
Button btnQLDocGia(101, w/2+25, 200 + 80, 300, 200, "QUAN LY DOC GIA", 0);
Button btnQLSach(102, w/2-325, 200 + 4*80, 300, 200, "MUON TRA SACH", 0);
Button btnThoat(104, w/2+25, 200 + 4*80, 300, 200, "THOAT", 0);

// Danh Muc Sach va DS DOC GIA
Button btnPrevDMS(207, XDMS[0], 520, 150, 50, "Trang truoc", 0);
Button btnNextDMS(208, XDMS[3]-150, 520, 150, 50, "Trang sau", 0);

// Nhap Sach
EditText edNhapSoLuongSach(1016, XDMS[0]+50, 715, 770, 40, "So luong sach :", "", "Toi da 99");
Button btnNhapSoLuongSach(217, w/2-50, 780, 100, 50, "NHAP", 0);

// Them Sach
EditText edThemMaSach(1014, XDMS[0]+10, 720, 850, 40, "Ma sach :", "", "Tu dong");
EditText edThemTrangThaiSach(1015, XDMS[0]+10, 770, 850, 40, "Trang thai [0,1,2] ", "", "0:Cho muon duoc- 1:Da cho muon- 2:Da thanh ly", TrangThaiSach);
EditText edThemViTriSach(1017, XDMS[0]+10, 820, 850, 40, "Vi tri :", "", "Toi da 18 ki tu");
Button btnThemSach(209, w/2-50, 870, 100, 50, "THEM", 0);

// Hieu Chinh Sach
EditText edHieuChinhMaSach(1014, XDMS[0]+30, 720, 850, 40, "Ma sach:", "", "Auto");
EditText edHieuChinhTrangThaiSach(1015, XDMS[0]+30, 770, 850, 40, "Trang thai [0,1,2]", "", "0:Cho muon duoc- 1:Da cho muon- 2:Da thanh ly", TrangThaiSach);
EditText edHieuChinhViTriSach(1015, XDMS[0]+30, 820, 850, 40, "Vi tri :", "", "Toi da 18 ki tu");
Button btnHieuChinhSach(217, w/2-50, 870, 100, 50, "EDIT", 0);
Button btnBackToNhapSach(210, XDMS[0], 610, 200, 35, "< BACK TO ADD", 0);

// Button Dau Sach
EditText edTimDauSach(1000, XXX[1]+50, 70, 650, 50, "Tim dau sach:", "", "Nhap ten sach vao day");
Button btnQuayVe(201, 20, 20, 100, 50, "< MENU", 0);
Button btnPrev(203, XXX[0], 770, 150, 50, "Trang truoc", 0);
Button btnNext(204, XXX[6]-150, 770, 150, 50, "Trang sau", 0);
Button btnClearTimDauSach(202, XXX[3]+50, 70, 100, 50, "Reset", 0);
Button btnAddDauSach(205, XXX[4]-180, 70, 170, 50, "Them Dau Sach", 0);

// Them Dau Sach
EditText edThemISBN(1002, XXX[7], 310, 700, 40, "ISBN :","","Chu va so, toi da 10 ki tu (bat dau bang chu)");
EditText edThemTenSach(1003, XXX[7], 360, 700, 40, "Ten sach :","","Chu va so, toi da 30 ki tu (bat dau bang chu)");
EditText edThemSoTrang(1004, XXX[7], 410, 700, 40, "So trang :","","So, toi da 5 ki tu");
EditText edThemTacGia(1005, XXX[7], 460, 700, 40, "Tac gia :","","Chu, toi da 30 ki tu");
EditText edThemNXB(1006, XXX[7], 510, 700, 40, "Nam xuat ban :","","So (dinh dang: 2022)");
EditText edThemTheLoai(1007, XXX[7], 560, 700, 40, "The loai :","","Chu, toi da 15 ki tu");
Button btnThemDauSach(205, w/2 - 150, 610, 150, 30, "THEM", 0);
Button btnClearThemDauSach(250, w/2 + 50, 610, 150, 30, "RESET", 0);
Button btnBack(206, 20, 20, 100, 50, "<BACK", 0);

// Hieu Chinh Dau Sach
EditText edHieuChinhISBN(1008, XXX[7], 310, 700, 40, "ISBN :","","Chu va so, toi da 10 ki tu (bat dau bang chu)");
EditText edHieuChinhTenSach(1009, XXX[7], 360, 700, 40, "Ten sach :","","Chu va so, toi da 30 ki tu (bat dau bang chu)");
EditText edHieuChinhSoTrang(1010, XXX[7], 410, 700, 40, "So trang :","","So, toi da 5 ki tu");
EditText edHieuChinhTacGia(1011, XXX[7], 460, 700, 40, "Tac gia :","","Chu, toi da 30 ki tu");
EditText edHieuChinhNXB(1012, XXX[7], 510, 700, 40,"Nam xuat ban :","","So (dinh dang: 2022)");
EditText edHieuChinhTheLoai(1013, XXX[7], 560, 700, 40, "The loai :","","Chu, toi da 15 ki tu");
Button btnHieuChinhDauSach(251, w/2 - 200, 610, 100, 30, "SAVE", 0);
Button btnClearHieuChinhDauSach(252, w/2-50, 610, 100, 30, "RESET", 0);
Button btnDeleteDauSach(253, w/2 + 100, 610, 100, 30, "DELETE", 0);

// button for PopUp
Button btnYes(254, w/2 -150, 490, 100, 30, "Yes", 0);
Button btnNo(255, w/2 + 50, 490, 100, 30, "No", 0);

//////////////////////////////////////////KHU TU TRI CUA DOCGIA VA MUONSACH /////////////////////////////////////////////////
char DocGiaTitle[] = "DANH SACH DOC GIA";
char *PhaiDocGia[5] = {"NAM", "NU"};
char *TTTDocGia[10] = {"KHOA", "HOAT DONG"};
char TTMuonTra[][10] = {"DANG MUON", "DA TRA", "LAM MAT"};
char ThemDocGia[] = "THEM DOC GIA";
char HieuChinhDocGia[] = "HIEU CHINH DOC GIA";
char XoaDocGia[] = "XOA DOC GIA";
char MuonSach[] = "MUON SACH";
char TraSach[] = "TRA SACH";
char TopTen[] = "TOP 10 CUON SACH MUON NHIEU NHAT";
char DSDM[] = "CAC SACH DANG MUON";

// X Danh sach Doc Gia
int XXXDG[8] = {200, 380, 1100, 1350, 1450, w-200, w-200, 600};
int XXXQH[8] = {200, 380, 1000, 1150, 1250, 1500, w-200};

int MUONTRA[] = {150, 200, 300, 750, 850, 1250, 1350, w-300, w-150}; //phan tu cuoi cung la vi tri cac edit box
// X Muon Tra sach
int XMT[5] = {50, 170, 570, 720, 920};

// Danh sach Doc Gia
Button btnTatCaDocGia(211, w/2 - 100, 80, 100, 50, "TAT CA", 0);
Button btnDocGiaQuaHan(212, w/2 , 80, 100, 50, "QUA HAN", 0);
Button btnSapXepTen(213, XXXDG[1], 80, 100, 50, "TEN", 0);
Button btnSapXepMaThe(214, XXXDG[1]+100, 80, 100, 50, "MA THE", 0);
Button btnThemMaThe(303, XXXDG[5]-150, 80, 150, 50, "THEM DOC GIA", 0);
Button btnQuayVeMenu(305, 20, 20, 100, 50, "< MENU", 0);
Button btnPrevDocGiaQH(215, XXX[0], 770, 150, 50, "Trang truoc", 0);
Button btnNextDocGiaQH(216, XXX[6]-150, 770, 150, 50, "Trang sau", 0);

// Them Doc Gia
EditText edThemMaTheDocGia(1002, XXX[7], 310, 700, 40, "Ma the:","","auto");
EditText edThemHoDocGia(1003, XXX[7], 360, 700, 40, "Ho va ten dem:","","Toi da 18 ki tu");
EditText edThemTenDocGia(1004, XXX[7], 410, 700, 40, "Ten:","","Toi da 10 ki tu");
EditText edThemPhaiDocGia(1005, XXX[7], 460, 700, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edThemTrangThaiTheDocGia(1006, XXX[7], 510, 700, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);
Button btnClearFormDocGia(304, w/2 + 50, 610, 150, 30, "RESET", 0);
Button btnThemDocGia(205, w/2 - 150, 610, 150, 30, "THEM", 0);

// Hieu Chinh Doc Gia
EditText edHieuChinhMaTheDocGia(1002, XXX[7], 310, 700, 40, "Ma the:","","khong cho phep");
EditText edHieuChinhHoDocGia(1003, XXX[7], 360, 700, 40, "Ho va ten dem:","","Toi da 18 ki tu");
EditText edHieuChinhTenDocGia(1004, XXX[7], 410, 700, 40, "Ten:","","Toi da 10 ki tu");
EditText edHieuChinhPhaiDocGia(1005, XXX[7], 460, 700, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edHieuChinhTrangThaiTheDocGia(1006, XXX[7], 510, 700, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);
Button btnHieuChinhDocGia(205, w/2 - 150, 610, 150, 30, "HIEU CHINH", 0);

// Xoa doc gia
Button btnXacNhanXoaDocGia(220, w/2 - 50, 600, 100, 40, "XOA", 0);

// Muon Tra Sach
Button btnBackToMenu(230, 20, 20, 100, 50, "< MENU", -1);
Button btnMuonSach(231, w/2 - 350 , 70, 150, 50, " MUON SACH", -1);
Button btnTraSach(232, w/2 -160, 70, 150, 50, "  TRA SACH", -1);
Button btnTopTen(233, w/2 +30, 70, 150, 50, "  TOP 10", -1);

// Muon sach
EditText edNhapMaDGMuonSach(1111, 460, 150, 620, 50, "Nhap ma the :", "", "Nhap ma the doc gia vao day");
EditText edNhapMaSachMuonSach(1112, w/2+150, 240, 600, 50, "Nhap ma sach :", "", "Nhap ma sach doc gia muon vao day");
EditText edNhapNgayMuonSach(1113, w/2+200, 700, 600, 50, "Ngay muon :", "", "01/01/2020");
Button btnTimMaDG(241, 1110, 150, 100, 50, "TIM", 0);
Button btnTimMaSach(242, w-200, 240, 100, 50, "TIM", 0);
Button btnXacNhanMuonSach(243, 1425, 775, 150, 50, "MUON SACH", 0);

// Tra sach
EditText edNhapNgayTraSach(1114, w/2+200, 500, 600, 50, "Ngay tra :", "", "01/01/2020");
Button btnXacNhanTraSach(244, w/2+400, 560, 140, 50, "TRA SACH", 0);
Button btnLamMatSach(300, w/2+550, 560, 140, 50, "MAT SACH?", 0);
Button btnXacNhanLamMatSach(301, w/2+300, 875, 200, 50, "XAC NHAN", 0);
Button btnHuyLamMatSach(302, w-400, 875, 200, 50, "HUY", 0);

bool isExit = false;
bool openFileSuccess = true;

Window Window;
SubWindow subWindow;
errorOpenfile error;
int curMenu = 0, curMenuMuonTra;
int curItem = -1, curItemSach = -1, curDauSach = -1, curSach = -1;
int totalNhapSach = 0, curNhapSach = 0;

int mx = -1, my = -1;//VI TRI CHUOT
bool canEditTrangThai = true;

int totalPageDauSach = 1, curPageDauSach = 1;
int totalPageSach = 1, curPageSach = 1;

void PopUp(char* confirm);
void ReadDauSachFromFile(DS_DauSach &DSDS);
void WriteDauSachToFile(DS_DauSach &DSDS);
void ClearScreen(int choice);
void DrawMenu();
void ButtonEffect(Button &btn);
void DauSachEvent(DS_DauSach &DSDS, TreeDocgia &DSDG);
void ItemEvent(DS_DauSach &DSDS);
void DrawBorderList();
void MenuEvent(DS_DauSach &DSDS, TreeDocgia &DSDG);
void DrawDanhSachDauSach();
void DrawNhapSach();
void Event();
void SetMenuSelect(DS_DauSach &DSDS, TreeDocgia &DSDG,int menuID);
void DrawListDSDS(DS_DauSach &DSDS);
void DrawThemDauSach();
void DrawHieuChinhDauSach();
void PopUp(string s);
void DrawItemDauSach(DS_DauSach &DSDS,int, int);
int GetItemDauSachPosition(DS_DauSach &DSDS,int y);
int GetItemSachPosition(DS_DauSach &DSDS,int y);
void DrawItemSach(Sach &sach, int i);
void ItemLeftMouseClick(DS_DauSach &DSDS, TreeDocgia &DSDG);
void ItemRightMouseClick(DS_DauSach &DSDS, TreeDocgia &DSDG);
void GetHieuChinhDauSach(DS_DauSach &DSDS,int i);
void Scan(DS_DauSach &DSDS, EditText* &txt, int maxn, ScanType type, int startLimit = 0, int endLimit = 0);
bool NumberOnly(int n,char c);
bool TextOnly(char c,bool comma);
int KiemTraNhapLieu(EditText* &txt, int n, char c);
bool ScanLimit(char c, int start, int end);
void ScanTimDauSach(EditText* &txt, int &n, int maxn, char c);

void MoveToNextDSDS(EditText &ISBN,EditText &TenSach,EditText &SoTrang,EditText &TacGia,EditText &NXB,EditText &TheLoai){
	if(Edit == &ISBN) Edit = &TenSach;
	else if(Edit == &TenSach) Edit = &SoTrang;
	else if(Edit == &SoTrang) Edit = &TacGia;
	else if(Edit == &TacGia) Edit = &NXB;
	else if(Edit == &NXB) Edit = &TheLoai;
	else if(Edit == &TheLoai) Edit = &ISBN;
}

void MoveToPrevDSDS(EditText &ISBN,EditText &TenSach,EditText &SoTrang,EditText &TacGia,EditText &NXB,EditText &TheLoai){
	if(Edit == &ISBN) Edit = &TheLoai;
	else if(Edit == &TenSach) Edit = &ISBN;
	else if(Edit == &SoTrang) Edit = &TenSach;
	else if(Edit == &TacGia) Edit = &SoTrang;
	else if(Edit == &NXB) Edit = &TacGia;
	else if(Edit == &TheLoai) Edit = &NXB;
}

//////////////////////////////////////////KHU TU TRI CUA DOCGIA VA MUONSACH /////////////////////////////////////////////////
DocGiaPTR root = NULL;
DocGia *curDGMT = NULL;
Node_ID *nodeStart = NULL;	// random ID doc gia
Sach *curSachMT = NULL;
DauSach * curDSMT = NULL;
bool sortDGByName = false;
bool canBorrow = false; //Doc gia co dang bi khoa hay khong de hien thi thanh tim kiem ma sach
bool canMT = false; // Doc Gia co the muon ma sach X hay khong?
int totalPageDG = 1, curPageDG = 1;
int totalPageDGQuaHan = 1, curPageDGQuaHan = 1;
int curItemDG = -1, curDG = -1;
int curItemMT = -1, curMT = -1;
int startIndexSach = -1;
bool CheckDocGia(EditText &MaThe, EditText &Ho, EditText &Ten, EditText &Phai, EditText &TrangThai, bool them);

void DrawBorderDSDocGia();
void DrawDanhSachDocGia(TreeDocgia &DSDG);
void DrawListDocGia(TreeDocgia &DSDG,bool reload = false);
void DrawItemDocGia(DocGia &docgia, int i, bool QUAHAN);
void DrawThemDocGia(bool genNewID = true);
void DrawHieuChinhDocGia();
void DrawMuonSach();
void DrawTraSach();
void DrawItemDocGiaQuaHan(DocGia &docgia, int soNgayQH, int i);
void DrawThongTinDocGia(DS_DauSach &DSDS, TreeDocgia &DSDG);
void DrawXoaDocGia(TreeDocgia &DSDG, int i);
void DrawThongTinSach();
void DrawLamMatSach();
void DrawThongTinSachTra(int itemMT);
void DrawBorderDSDocGiaQuaHan();
void DrawTopTen(DS_DauSach &DSDS);
void MoveToNextDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia);
void MoveToPrevDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia);
void ButtonSwitchClick(TreeDocgia &DSDG);
int GetItemDocGiaPosition(TreeDocgia &DSDG, int y);
void ItemDocGiaEvent(TreeDocgia &DSDG);
void DocGiaEvent(DS_DauSach &DSDS, TreeDocgia &DSDG);
void ItemMTEvent();
void DrawItemMT(int i);
void ItemMTClick();
void MuonTraEvent(DS_DauSach &DSDS, TreeDocgia &DSDG);
void WriteDauSachToFile(DS_DauSach &DSDS);
void WriteDocGiaToFile(DocGiaPTR &root);

void Load_Found_DS(DS_DauSach &DSDS,EditText* &txt,int &n){
	GetListNodes(DSDS, txt->content, sizeListIndexDauSachSearch);
	curPageDauSach = 1;
	ClearScreen(5);
	DrawListDSDS(DSDS);		
}

void ScanTimDauSach(DS_DauSach &DSDS,EditText* &txt, int &n, int maxn, char c){
	if(c == BACKSPACE)
		if(n > 0)
			txt->content[n--] = ' ';
		else if(n==0) //tu dong load lai danh sach neu da xoa het tu khoa tim kiem
			Load_Found_DS(DSDS, txt, n);
	if(n < maxn){
		if(c == SPACE){
			if(n > 0 && txt->content[n-1] != ' '){ //tim kiem khi ket thuc moi tu bang nut space
				Load_Found_DS(DSDS, txt, n);
				txt->content[n++] = ' ';
			}		
		}
		else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			txt->content[n++] = toupper(c);		
	}
}

bool NumberOnly(int n, char c){
	if(c >= '0' && c <= '9'){
		if((n == 0 && c != '0')|| (n>0))
			return true; 		
	}
    return false;
}

bool TextOnly(char c, bool COMMA){
	int comma = 0;
	char ch{ comma };
	if(COMMA)
		ch = 44;	//phim ','
	else 
		ch = 32; //phim 'space' _
		
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c==' ')||(c==ch)||(c=='-'))
		return true;   
    return false;
}

int KiemTraNhapLieu(EditText* &txt, int n, char c){
	if((n == 0 && c == ' ') ||(n != 0 && c == ' ' && txt->content[n-1] == ' '))//xoa bo space dau va 2 space giua 2 chu 
        return 0;
    else if((n != 0 && txt->content[n-1] == ' ' && c != ' ') || (n == 0 && c != ' '))//viet hoa chu cai dau sau dau cach
        return 1;
    else if((n != 0 && c == ' ' && txt->content[n-1] != ' '))//khong bao gom dau space trong chuoi
        return -1;      
    return 3;//chuoi hop le khong can xu ly
}

bool ScanLimit(char c, int start, int end){
	if(c >= start && c <= end)
		return true;		
	return false;	
}

void Scan(DS_DauSach &DSDS, EditText* &txt, int maxn, ScanType type, int startLimit, int endLimit){
	if(txt == NULL) return;
	int mx = -1, my = -1, mrx = -1, mry = -1;
	int n = strlen(txt->content);

	getmouseclick(WM_LBUTTONDOWN, mx, my);
	clearmouseclick(WM_LBUTTONDOWN);
	
	getmouseclick(WM_RBUTTONDOWN, mrx, mry);
	clearmouseclick(WM_RBUTTONDOWN);
				
	if(((mx != -1 && my != -1) || (mrx != -1 && mry != -1)) && (!txt->isMouseHover(mx, my))){
		txt->content[n] = '\0';
		txt->draw();
		txt = NULL;
		return;
	}	
	if(kbhit()){
		char c = getch();
		if(c == BACKSPACE && type != TIM_DAU_SACH){
			if(n > 0){
				txt->content[n--] = ' ';
				txt->content[n] = '\0';
			}
		}else if(n < maxn){
			switch (type){			
                case ONLY_NUMBER: //nhap so
                if(NumberOnly(n,c))
						txt->content[n++] = c;	
                break;
                
                case ONLY_TEXT://chi chu thuong hoac theo nguoi dung nhap vao
                if(TextOnly(c,false) &&  KiemTraNhapLieu(txt,n,c) == 3)
				    txt->content[n++] = c;
                break;
                
                case TEXT_NUM_ADD_COMMA_UPPERCASE://chi chu thuong hoac theo nguoi dung nhap vao + dau phay
                if((TextOnly(c,true)) || NumberOnly(n,c))
                	if((KiemTraNhapLieu(txt,n,c) == 0))
                		txt->content[n++] = '\0';
					else
						txt->content[n++] = toupper(c);
                break;
                
                case TEXT_NUMBER://chu + so
                if(TextOnly(c,false) || NumberOnly(n,c)){
                	if((KiemTraNhapLieu(txt,n,c) == 0))
                		txt->content[n++] = '\0';
					else
						txt->content[n++] = c;
				}
                break;
                
                case SPACE_TEXT://form Aaa Bbb Ccc
                if(TextOnly(c,false))  
   					if (KiemTraNhapLieu(txt,n,c) == 0)  
						txt->content[n++] = '\0';              
					else if (KiemTraNhapLieu(txt,n,c) == 1)  
						txt->content[n++] = toupper(c);   					   
					else 
						txt->content[n++] = tolower(c);               			
                break;
                
                case SPACE_TEXT_UPPERCASE://form ABC DEF
                if(TextOnly(c,false)){
   					if (KiemTraNhapLieu(txt,n,c) == 0)  
						txt->content[n++] = '\0';                					   
					else 
						txt->content[n++] = toupper(c);                 	
				}			                                      
                break;
                
                case DELETE_SPACE_UPPERCASE://xoa space dau va space giua, form ISBN: TDK
                if(TextOnly(c,false) || NumberOnly(n,c)){
                	if(KiemTraNhapLieu(txt,n,c) == 0 || KiemTraNhapLieu(txt,n,c) == -1){
                		txt->content[n++] = '\0';
					}
					else {
						txt->content[n++] = toupper(c); 
					}
				}
                break;
                
                case LIMIT_CHARACTER://so gioi han
                if(ScanLimit(c,startLimit, endLimit))
				    txt->content[n++] = c;
                break;
                
                case TIM_MA_SACH://so gioi han
                if(TextOnly(c,false)|| NumberOnly(n,c))  
   					if (KiemTraNhapLieu(txt,n,c) == 0)  
						txt->content[n++] = '\0';              					   
					else 
						txt->content[n++] = toupper(c);               			
                break;
            }
            if(type == TIM_DAU_SACH)
            	ScanTimDauSach(DSDS, txt, n, maxn, c);
				
			txt->content[n] = '_';
			txt->draw();
			txt->content[n] = '\0';
		}
	}
}

void KeyBoardEvent(DS_DauSach &DSDS){
	if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT)){
		ClearScreen(4);//khong nhan 2 phim tro < , > 
		return;
	}
	if(GetAsyncKeyState(VK_DOWN)){
		delay(200);
		ClearScreen(4);
		if(Edit != NULL){
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			if (Window == THEM_DAU_SACH)
				MoveToNextDSDS(edThemISBN,edThemTenSach,edThemSoTrang,edThemTacGia,edThemNXB,edThemTheLoai);
			else if (Window == HIEU_CHINH_DAU_SACH)
				MoveToNextDSDS(edHieuChinhISBN,edHieuChinhTenSach,edHieuChinhSoTrang,edHieuChinhTacGia,edHieuChinhNXB,edHieuChinhTheLoai);
			else if (Window == THEM_DOC_GIA)
				MoveToNextDSDG(edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia);
			else if (Window == HIEU_CHINH_DOC_GIA)
				MoveToNextDSDG(edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia);
		}
		return;
	}else if(GetAsyncKeyState(VK_UP)){
		delay(300);
		ClearScreen(4);
		if(Edit != NULL){
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			if (Window == THEM_DAU_SACH)
				MoveToPrevDSDS(edThemISBN,edThemTenSach,edThemSoTrang,edThemTacGia,edThemNXB,edThemTheLoai);
			else if (Window == HIEU_CHINH_DAU_SACH)
				MoveToPrevDSDS(edHieuChinhISBN,edHieuChinhTenSach,edHieuChinhSoTrang,edHieuChinhTacGia,edHieuChinhNXB,edHieuChinhTheLoai);
			else if (Window == THEM_DOC_GIA)
				MoveToPrevDSDG(edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia);
			else if (Window == HIEU_CHINH_DOC_GIA)
				MoveToPrevDSDG(edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia);			
		}
		return;
	}	
	if(Edit != NULL){
		int n = strlen(Edit->content);
		Edit->content[n] = '_';
		Edit->draw();
		Edit->content[n] = '\0';
		
		if(curMenu == btnQLDauSach.id){
			if(Window == DANH_SACH_DAU_SACH && Edit == &edTimDauSach){
				Scan(DSDS, Edit, 20, TIM_DAU_SACH);			
			}
				
			else if(Window == THEM_DAU_SACH){
				if(Edit == &edThemISBN)
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				else if(Edit == &edThemTenSach)
					Scan(DSDS, Edit, 30, TEXT_NUMBER);
				else if(Edit == &edThemSoTrang)
					Scan(DSDS, Edit, 5, ONLY_NUMBER);
				else if(Edit == &edThemTacGia)
					Scan(DSDS, Edit, 30, SPACE_TEXT);
				else if(Edit == &edThemNXB)
					Scan(DSDS, Edit, 4, ONLY_NUMBER);
				else if(Edit == &edThemTheLoai)
					Scan(DSDS, Edit, 15, SPACE_TEXT_UPPERCASE);								
			}
			else if (Window == HIEU_CHINH_DAU_SACH){
				if(Edit == &edHieuChinhISBN)
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				else if(Edit == &edHieuChinhTenSach)
					Scan(DSDS, Edit, 30, TEXT_NUMBER);
				else if(Edit == &edHieuChinhSoTrang)
					Scan(DSDS, Edit, 5, ONLY_NUMBER);
				else if(Edit == &edThemTacGia)
					Scan(DSDS, Edit, 30, SPACE_TEXT);
				else if(Edit == &edHieuChinhNXB)
					Scan(DSDS, Edit, 4, ONLY_NUMBER);
				else if(Edit == &edHieuChinhTheLoai)
					Scan(DSDS, Edit, 15, SPACE_TEXT_UPPERCASE);		
			}				
			else if(Window == DANH_MUC_SACH){
				if(subWindow == NHAP_SACH && Edit == &edNhapSoLuongSach)
					Scan(DSDS, Edit, 2, ONLY_NUMBER);
																									
				else if(subWindow == HIEU_CHINH_SACH){
					if(Edit == &edHieuChinhTrangThaiSach)
						Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '2');
					else if(Edit == &edHieuChinhViTriSach)
						Scan(DSDS, Edit, 20, TEXT_NUM_ADD_COMMA_UPPERCASE);						
				}												
				else if(subWindow == THEM_SACH){
					if (Edit == &edThemTrangThaiSach)
						Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '2');	
					else if (Edit == &edThemViTriSach)
						Scan(DSDS, Edit, 20, TEXT_NUM_ADD_COMMA_UPPERCASE);					
				}													
			}				
		}
		else if(curMenu == btnQLDocGia.id){
			if(Window == THEM_DOC_GIA){
				if(Edit == &edThemHoDocGia)
					Scan(DSDS, Edit, 18, SPACE_TEXT_UPPERCASE);
				else if(Edit == &edThemTenDocGia)
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				else if(Edit == &edThemPhaiDocGia)
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				else if(Edit == &edThemTrangThaiTheDocGia)
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				
			}else if(Window == HIEU_CHINH_DOC_GIA){
				if(Edit == &edHieuChinhHoDocGia)
					Scan(DSDS, Edit, 18, SPACE_TEXT_UPPERCASE);
				else if(Edit == &edHieuChinhTenDocGia)
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				else if(Edit == &edHieuChinhPhaiDocGia)
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				else if(Edit == &edHieuChinhTrangThaiTheDocGia)
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
			}
		}
		else if(curMenu == btnQLSach.id){
			if(Edit == &edNhapMaDGMuonSach)
				Scan(DSDS, Edit, 5, ONLY_NUMBER);
			else if(Edit == &edNhapMaSachMuonSach)
				Scan(DSDS, Edit, 15, TIM_MA_SACH);
//			else if(Edit == &edNhapNgayMuonSach){
//				Scan(Edit, 10, DATE_TIME);
//			}		
//			if(Edit == &edNhapNgayTraSach){
//				Scan(Edit, 10, DATE_TIME);
//			}
		}
	else
		ClearScreen(4);
	}
}

void Event(DS_DauSach &DSDS,TreeDocgia &DSDG){
	mx = mousex(); my = mousey();
	KeyBoardEvent(DSDS);
	if(curMenu == 0)
		MenuEvent(DSDS, DSDG);
	else if(curMenu == btnQLSach.id)
		MuonTraEvent(DSDS, DSDG);
	else if(curMenu == btnQLDauSach.id)
		DauSachEvent(DSDS, DSDG);
	else if(curMenu == btnQLDocGia.id)
		DocGiaEvent(DSDS, DSDG);
} 

void MenuEvent(DS_DauSach &DSDS, TreeDocgia &DSDG){	
	if(openFileSuccess == false){
		ButtonEffect(btnYes);
		ButtonEffect(btnNo);
		if(GetAsyncKeyState(VK_LBUTTON)){
			if(btnYes.isMouseHover(mx, my)){
				isExit = true;
			}
			else if(btnNo.isMouseHover(mx, my)){
				openFileSuccess = true;
				ClearScreen(0);
				DrawMenu();
			}
		}
	}
	else{
		ButtonEffect(btnQLDauSach);
		ButtonEffect(btnQLDocGia);
		ButtonEffect(btnQLSach);
		ButtonEffect(btnThoat);	
		if(GetAsyncKeyState(VK_LBUTTON)){
			if(btnQLDauSach.isMouseHover(mx, my))
				SetMenuSelect(DSDS, DSDG, btnQLDauSach.id);
			else if(btnQLDocGia.isMouseHover(mx, my))
				SetMenuSelect(DSDS, DSDG, btnQLDocGia.id);
			else if(btnQLSach.isMouseHover(mx, my))
				SetMenuSelect(DSDS, DSDG, btnQLSach.id);
			else if(btnThoat.isMouseHover(mx, my)){	
				WriteDauSachToFile(DSDS);
				WriteDocGiaToFile(root);
				cout<<"Saved dau sach + danh muc sach \n";
				while(DSDS.n) {
					DeleteAllNodeSach(DSDS.nodes[DSDS.n-1]->First);
					delete DSDS.nodes[--DSDS.n];
				}
				
				if(root != NULL){
					DeleteMemoryDocGia(root->left);
					DeleteMemoryDocGia(root->right);		
					DeleteAllMuonTra(root->docgia.mt);		
					delete root;
				}
				cout<<"Free memory danh muc sach \n";
				isExit = true;
			}		
		}		
	}
}

void SetMenuSelect(DS_DauSach &DSDS, TreeDocgia &DSDG, int menuID){
	if(curMenu != menuID){
		curMenu = menuID;
		ClearScreen(0);
		
		if(curMenu == 0)
			DrawMenu();	
		else if(menuID == btnQLDauSach.id){
			Window = DANH_SACH_DAU_SACH;
			subWindow = THEM_SACH;
		    DrawDanhSachDauSach();	
		    DrawListDSDS(DSDS);
		}		
		else if(menuID == btnQLDocGia.id){
			Window = DANH_SACH_DOC_GIA;
			DrawDanhSachDocGia(DSDG);
		}	
		else if(menuID == btnQLSach.id){
			Window = MUON_SACH;
			DrawMuonSach();	
		}	
	}	
}

void ButtonEffect(Button &btn){
	if(btn.isChoose) return;
	
	if(btn.isMouseHover(mousex(), mousey())){
		if(btn.isHover == false){
			btn.isHover = true;
			btn.draw();	
		}		
	}		
	else{
		if(btn.isHover == true){
			btn.isHover = false;
			btn.draw();  			
		}
	}
}

void PopUp(char* confirm){
	setfillstyle(USER_FILL, TEXT_COLOR_SELECTED);
	setcolor(BORDER_COLOR);
	bar((w/2)-300, 380, (w/2)+300, 550);
	setcolor(BG_COLOR);
	setbkcolor(TEXT_COLOR_SELECTED);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy((w/2) - textwidth(confirm)/2, 415-textheight(confirm)/2, confirm);
	btnYes.draw();
	btnNo.draw();
}

void DrawMenu(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 7);
	setcolor(TEXT_COLOR);
	setbkcolor(BG_COLOR);
	outtextxy(w/2-textwidth(AppTitle)/2, 100, AppTitle);
	setlinestyle(SOLID_LINE, 0, 3);	
	rectangle(w/2-480, 100, w/2+480, 180);//vien quanh tieu de	
	rectangle(w/2-480, 183, w/2+480, 800);	
	btnQLDauSach.draw();
	btnQLDocGia.draw();
	btnQLSach.draw();
	btnThoat.draw();
	char confirm[50];
	if(openFileSuccess == false){
		switch(error){
			case DAU_SACH: 
			{
				strcpy(confirm, "Mo file DAU SACH loi, thoat ung dung?");
				break;				
			}
			case SACH: 
			{
				strcpy(confirm, "Mo file SACH loi, thoat ung dung?");
				break;	
			}

			case DOC_GIA: 
			{
				strcpy(confirm, "Mo file DOC GIA loi, thoat ung dung?");
				break;				
			}
			case MUON_TRA:
			{
				strcpy(confirm, "Mo file MUON TRA loi, thoat ung dung?");
				break;				
			} 
			default :
				{
					strcpy(confirm, "ok");
				}		
		}
		subWindow = CONFIRM_POPUP;
		PopUp(confirm);
	}
} 

void MoveToNextDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia){
	if(Edit == &HoDocGia) Edit = &TenDocGia;
	else if(Edit == &TenDocGia) Edit = &PhaiDocGia;
	else if(Edit == &PhaiDocGia) Edit = &TrangThaiTheDocGia;
	else if(Edit == &TrangThaiTheDocGia) Edit = &HoDocGia;
}

void MoveToPrevDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia){
	if(Edit == &HoDocGia) Edit = &TrangThaiTheDocGia;
	else if(Edit == &TenDocGia) Edit = &HoDocGia;
	else if(Edit == &PhaiDocGia) Edit = &TenDocGia;
	else if(Edit == &TrangThaiTheDocGia) Edit = &PhaiDocGia;
}

void ClearScreen(int choice){
	switch (choice) {
		case 1://xoa toan man hinh 
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(0, 0, w, h); 
			break;
			
		case 2://Clear Content ThemDauSach
			memset(edThemISBN.content, 0, sizeof(edThemISBN.content));
			memset(edThemTenSach.content, 0, sizeof(edThemTenSach.content));
			memset(edThemSoTrang.content, 0, sizeof(edThemSoTrang.content));
			memset(edThemTacGia.content, 0, sizeof(edThemTacGia.content));
			memset(edThemNXB.content, 0, sizeof(edThemNXB.content));
			memset(edThemTheLoai.content, 0, sizeof(edThemTheLoai.content));
			memset(mess, 0, sizeof(mess));			
			break;
			
		case 3://Clear Content HieuChinhDauSach
			memset(edHieuChinhTenSach.content, 0, sizeof(edHieuChinhTenSach.content));
			memset(edHieuChinhSoTrang.content, 0, sizeof(edHieuChinhSoTrang.content));
			memset(edHieuChinhTacGia.content, 0, sizeof(edHieuChinhTacGia.content));
			memset(edHieuChinhNXB.content, 0, sizeof(edHieuChinhNXB.content));
			memset(edHieuChinhTheLoai.content, 0, sizeof(edHieuChinhTheLoai.content));
			memset(mess, 0, sizeof(mess));			
			break;
			
		case 4://khong nhan 2 phim tro < , >
			while(kbhit()){
				char c = getch();
			}		
			break;
			
		case 5: //clear noi dung cua list DAU SACH, DOC GIA
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XXX[0], 230, XXX[6], 750);
			break;
			
		case 6: //Clear Content ThemDocGia
			memset(edThemMaTheDocGia.content, 0, sizeof(edThemMaTheDocGia.content));	
			memset(edThemHoDocGia.content, 0, sizeof(edThemHoDocGia.content));	
			memset(edThemTenDocGia.content, 0, sizeof(edThemTenDocGia.content));	
			memset(edThemPhaiDocGia.content, 0, sizeof(edThemPhaiDocGia.content));	
			memset(edThemTrangThaiTheDocGia.content, 0, sizeof(edThemTrangThaiTheDocGia.content));
			break;		

		case 7: //Clear Content HieuChinhDocGia
			memset(edHieuChinhMaTheDocGia.content, 0, sizeof(edHieuChinhMaTheDocGia.content));	
			memset(edHieuChinhHoDocGia.content, 0, sizeof(edHieuChinhHoDocGia.content));	
			memset(edHieuChinhTenDocGia.content, 0, sizeof(edHieuChinhTenDocGia.content));	
			memset(edHieuChinhPhaiDocGia.content, 0, sizeof(edHieuChinhPhaiDocGia.content));	
			memset(edHieuChinhTrangThaiTheDocGia.content, 0, sizeof(edHieuChinhTrangThaiTheDocGia.content));
			break;	
		
		case 8: //ClearLayoutListDocGia
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XXXQH[0]-5, 150-5, w-20, 820);	
			break;
		
		case 9: //ClearLayoutListDocGiaQuaHan
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XXXQH[0]-5, 150-5, w-20, 820);		
			
		default:// xoa toan man hinh
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(0, 0, w, h); 
			break;
		}	
};

