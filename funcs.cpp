ostream& operator<<(ostream& os, const nm::jets& Jets){
    os << Jets.model <<" "<< Jets.pilot << " " << Jets.range << " " << Jets.speed<< " "<<Jets.status<< " " <<Jets.time<<" "<< Jets.x<<" "<< Jets.y<<" "<< Jets.timeEnd;
    return os;
}

istream& operator>>(istream& is, nm::jets& Jets){
    is >> Jets.model >> Jets.pilot >> Jets.range >> Jets.speed>>Jets.status>>Jets.time>>Jets.x>>Jets.y>>Jets.timeEnd;
    return is;
}


void nm::chek(string a){
    ifstream f(a);
    f.open(a);
    if(!f.is_open()){
    cout << "Файл, необходимый для работы, не найден. Создается новый файл:"<<a<<" \n";
    ofstream f(a);
            if (f.is_open()){
                cout<< "Не удалось создать файл. Программа будет завершена"<<endl;
                exit(EXIT_FAILURE);
            } }
    f.close();
    }

void nm::display(string a){
    string line;
    ifstream f;
    f.open(a); // окрываем файл
    if(!f.is_open()) fatal();
    bool flag = true;
    int b=0;
    if(a=="jets.txt"){
        cout << "Модель самолета| Пилот| Путь | Км/ч | Статус  | В пути | Положение(х,у) | Оставшееся время полета" << endl;}
        else {
        cout << "Маршрут\t| Начало(x,y)\t| Конец(х,у)" << endl;}
        while (getline(f, line)) {
            for (char& t : line) {
                if (t == ' ') {
                    t = '\t';
                }
            }
            cout << b<<". "<<line << endl;
            flag = false;
            b++;
        }
        if(flag) cout << "Файл пуст" << endl;
    f.close();



}

void nm::searchJET(){
    cout << "Enter model of jet" << endl;
    string Model;
    cin >> Model;
    jets editable;
    ifstream f;
    f.open("jets.txt");
    if(!f.is_open()) fatal();
    while(f >> editable){
        if(editable.model == Model){
            cout << editable.model << " " << editable.pilot<< " " << editable.range << " " << editable.speed << " "<<editable.status<< " " <<editable.time <<" " <<editable.x<<" " <<editable.y <<" " <<editable.timeEnd<< endl;
        }
    }
    f.close();
}

void nm::addJET(){
    jets editable;
    cout << "Введите название самолета" << endl;
    cin >> editable.model;
    cout << "Введите имя пилота" << endl;
    cin >> editable.pilot;
    cout << "Введите скорость самолета" << endl;
    if (!(cin >> editable.speed)||(editable.speed<=0)) {
                cout << "Ошибка при вводе скорости" <<endl;
            return;}
    fstream f;
    editable.range = "no";
    editable.status = 0;
    editable.time = 0;
    editable.x=0;
    editable.y=0;
    editable.timeEnd=0;
    f.open("jets.txt", ios::app | ios::ate);
    if(!f.is_open()) fatal();
    f << editable.model << " " << editable.pilot << " " << editable.range << " " << editable.speed << " "<< editable.status << " " << editable.time <<" "<<editable.x<<" "<< editable.y<<" "<<editable.timeEnd<< endl;
    f.close();
}

void nm::delJET(){
    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);

    int index;
    cout << "Введите индекс самолета" << endl;
    if (!(cin >> index)||(index<0)||(index>i)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open()) fatal();
    for(int n = 0; n < i; n++){
        if(n!=index){
            fwrite << arr[n].model << " " << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<<arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
        }
    }
    fwrite.close();

}
