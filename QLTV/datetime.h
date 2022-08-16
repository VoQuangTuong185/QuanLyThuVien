char* GetSystemDate(){
	//time(0): nhan vao 1 con tro, luu gia tri x la so giay tinh tu epoch (1970-01-01 00:00:00 UTC)
	//vao noi ma con tro dang tro toi va tra ve x
	time_t curTime = time(0);
	tm* now = localtime(&curTime);
	char* ch = new char;
	//gui ouput da duoc dinh dang toi chuoi ch
	sprintf(ch, "%d/%d/%d", now->tm_mday, now->tm_mon+1, 1900+now->tm_year);
	return ch;
}

int* SplitDate(char s[]){
	int *a = new int[3];
	for(int i=0; i<3; i++) 
		a[i] = -1;
	string txt;
	int index = 0;
	int n = strlen(s);
	for(int i=0; i<n; i++){
		if(s[i] == '/' || i == n-1){
			if(i == n-1) 
				txt += s[i];
			//c_str: This array includes the same sequence of characters that make up the value of the string object 
			//plus an additional terminating null-character ('\0') at the end 
			//string => C-string
			int x = atoi(txt.c_str());
			//Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int
			a[index] = x;
			index++;
			txt = "";
		}else
			txt += s[i];
	}
	return a;
}

//Every year that is exactly divisible by 4 is a leap year, 
//except for years that are exactly divisible by 100, 
//but these centurial years are leap years if they are exactly divisible by 400. 
bool isLeapYear(int year){
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0))
		return true;
	return false;
}

int DayOfMonth(int month, int year){
	if(month < 1 || month > 12) return 0;
	
	switch(month){
		case 2:
			if(isLeapYear(year)) return 29;
			else return 28;
		case 4:
		case 6:
		case 9:
		case 11: return 30;
	}
	return 31;
}

bool CheckDate(char* s){
	int *a = SplitDate(s);
	bool check = true;
	if(a[2] < 1900 || a[1] <= 0 || a[1] > 12 || a[0] <= 0) 
		check = false;
	if(a[0] > DayOfMonth(a[1], a[2])) 
		check = false;
	delete a;
	return check;
}

time_t GetTime(char *s){
	tm t;
	int *a = SplitDate(s);
	t.tm_year = a[2]-1900;
	t.tm_mon = a[1]-1;
	t.tm_mday = a[0];
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	//Convert tm structure to time_t
	//which may be modified
	time_t timer = mktime(&t);
	delete a;
	return timer;
}

double DiffTime(char *time1, char *time2){
	time_t t1 = GetTime(time1);
	time_t t2 = GetTime(time2);
	return difftime(GetTime(time1), GetTime(time2));
	//return number of seconds GetTime(time1) greater GetTime(time2)
}



