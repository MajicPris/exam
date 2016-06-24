/создание циклического однонаправленного списка 
void Make_Circle_Single_List(int n,
       Circle_Single_List** Head,Circle_Single_List* Loop){
    if (n > 0) {
        (*Head) = new Circle_Single_List();
        //выделяем память под новый элемент
        if (Loop == NULL) Loop = (*Head);
        cout << "Введите значение ";
        cin >> (*Head)->Data;
        //вводим значение информационного поля
        (*Head)->Next=NULL;//обнуление адресного поля
        Make_Circle_Single_List(n-1,&((*Head)->Next),Loop);
    }
    else {
        (*Head) = Loop;
    }
}

//печать циклического однонаправленного списка
void Print_Circle_Single_List(Circle_Single_List* Head) {
    Circle_Single_List* ptr=Head; 
    //вспомогательный указатель
    do {
       cout << ptr->Data << "\t";
       ptr=ptr->Next;
    } while (ptr!=Head);
    cout << "\n"; 
}

/*вставка элемента после заданного номера в циклический однонаправленный список*/
Circle_Single_List* Insert_Item_Circle_Single_List(Circle_Single_List* Head, 
      int Number, int DataItem){
  Circle_Single_List *Current = Head;
  //встали на первый элемент
  Circle_Single_List *NewItem = new(Circle_Single_List);
  //создали новый элемент   
  NewItem->Data = DataItem; 
  if (Head == NULL) {//список пуст
    NewItem->Next = NewItem;
    Head = NewItem;
  }
  else {//список не пуст
    for (int i = 1; i < Number; i++)
      Current = Current->Next;
    NewItem->Next = Current->Next;
    Current->Next = NewItem;
  }
  return Head;
}

/*удаление элемента с заданным номером из циклического однонаправленного списка*/
Circle_Single_List* Delete_Item_Circle_Single_List
      (Circle_Single_List* Head, int Number){
  if (Head != NULL){
    Circle_Single_List *Current = Head;
    if (Head->Next != Head){
      for (int i = 1; i < Number; i++)
        Current = Current->Next;
        Circle_Single_List *ptr = Head;
      while (ptr->Next != Current)
        ptr = ptr->Next;
      //непосредственное удаление элемента
      ptr->Next = Current->Next;
      if (Head = Current) Head = Current->Next;
      delete(Current);
    }
    else{
      Head = NULL;
      delete(Current);
    }
  }
  return Head;
}

//поиск элемента в циклическом однонаправленном списке
bool Find_Item_Circle_Single_List(Circle_Single_List* Head, 
         int DataItem){
  Circle_Single_List *ptr = Head; 
  //вспомогательный указатель
  do {
    if (DataItem == ptr->Data) return true; 
    else ptr = ptr->Next;
    }
  while (ptr != Head);
  return false;
}

//проверка пустоты циклического однонаправленного списка
bool Empty_Circle_Single_List(Circle_Single_List* Head){
  return (Head != NULL ? false : true);
}

//удаление циклического однонаправленного списка
void Delete_Circle_Single_List(Circle_Single_List* Head){
  if (Head != NULL){
    Head = Delete_Item_Circle_Single_List(Head, 1);
    Delete_Circle_Single_List(Head);
  } 
}
