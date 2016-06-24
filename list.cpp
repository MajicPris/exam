#include <iostream>
#include <cstdlib>
#include <ctime>
 
struct TPoint
{
   int x, y;
 
   TPoint(): x(0), y(0) { ; }
   TPoint(int theX, int theY): x(theX), y(theY) { ; }
};
 
struct TNode
{
   TPoint point;
   TNode* next;
   TNode* prev;
};
 
//----------------------------------------------//
// Добавление элемента в список. Добавление происходит в
// начало списка, а не в конец, хотя исправить - минутное дело
// Параметры: list -  сам список
//            point - данные для добавления
TNode* Push(TNode*& list, const TPoint& point)
{
   // Создаём новый узел
   TNode* node = new TNode;
   node->point = point;
 
   // В случае пустого списка просто закольцовываем
   // на себя
   if (list == NULL)
   {
      node->next = node->prev = node;
   }
   // В случае не пустого списка, вставляем созданный
   // элемент в начало списка
   else
   {
      // Сначала расставляем указатели в созданном элементе
      node->next = list;
      node->prev = list->prev;
      // А теперь скрепляем с имеющимся
      list->prev = node;
      node->prev->next = node;
   }
 
   list = node;
 
   return list;
}
//----------------------------------------------//
// Удаление элемента из списка
// Параметры:  list -  сам список
// Возвращает: значение удалённого узла
TPoint Pop(TNode*& list)
{
   // Если список пуст, то закрываем лавочку
   if (list == NULL)
   {
      return TPoint();
   }
 
   // Сохраняем значение текущего узла, ибо он
   // сейчас будет удалён
   TPoint val(list->point);
   TNode* node = list;
 
   // В случае если в списке был всего один элемент,
   // то просто зануляем наш список
   if ((list->next == list) || (list->prev == list))
   {
      list = NULL;
   }
   // Иначе перебиваем указатели буз учёта
   // удаляемого элемента.
   else
   {
      list->prev->next = list->next;
      list->next->prev = list->prev;
      list = list->next;
   }
   // Удаляем отцепленный узел
   delete node;
 
   return val;
}
//----------------------------------------------//
// Перегрузка оператора вывода для структуры TPoint
// P.S.: Себя капитаном очевидностью чувствую :(
std::ostream& operator << (std::ostream& os, const TPoint& point)
{
   os << "[" << point.x << "," << point.y << "]";
 
   return os;
}
//----------------------------------------------//
// Перегрузка для списка (struct TNode*)
std::ostream& operator << (std::ostream& os, const TNode* node)
{
   if (node)
   {
      const TNode* cursor = node;
 
      for (; cursor->next != node; cursor = cursor->next)
      {
         os << cursor->point << " ";
      }
      os << cursor->point;
   }
   else
   {
      os << "nil";
   }
 
   return os;
}
//----------------------------------------------//
 
int main()
{
   srand(time(NULL));
 
   TNode* list = NULL;
 
   // Случайным образом задаём 5 точек и добавляем их в список
   // После чего сразу же выводим (и саму точку и список)
   for (int i = 0; i < 5; ++i)
   {
      TPoint point(rand()%100 - 50, rand()%100 - 50);
      Push(list, point);
      std::cout << "addition: " << point << std::endl;
      std::cout << "list: " << list << std::endl;
   }
 
   // Пока в списке есть хоть один элемент
   // удаляем верхний элемент в списке и выводим результат
   while (list)
   {
      std::cout << "deleted: " << Pop(list) << std::endl;
      std::cout << "list: "  << list << std::endl;
   }
 
   system("pause");
 
   return 0;
}
