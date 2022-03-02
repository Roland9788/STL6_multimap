#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*
Модифицированный вариант map, в котором отсутствует требования уникальности ключа — то есть, если
произвести поиск по ключу, то вернется не одно значение,
а набор значений, сохраненных с данным ключом.
Класс multimap поддерживает поддерживает ассоциативный контейнер, в котором неуникальным (в общем
случае) ключам соответствуют определённые значения.
Спецификация его шаблона имеет следующий вид:
template <class Key, class T, class Comp = less<key>,
class Allocator =Alloctor<pair<const key, T>>>
class multimap
Здесь key — тип данных ключей, T — тип сохраняемых
(отображаемых)значений, а Comp — функция, которая
сравнивает два ключа. Класс multimap имеет следующие
конструкторы:
explicit multimap(const Comp &cmpfn =
Comp(),Allocator &a = Allocator());
multimap(multimap<Key, T, Comp,Allocator> &ob);
template < class InIter> multimap(InIter start,
InIter end,const Comp &cmpfn = Comp(),
const Allocator &a = Allocator());
Первая форма конструктора создает пустое мультиотображение. Вторая создает мультиотображение, которое
содержит те же элементы, что и мультиотображение ob.
Третья создает мультиотображение, которое содержит
элементы в диапазоне, заданном параметрами start и end.
Функция, заданная параметром cmpfn (и если она задана),
определяет упорядочение мультиотображения.
Для класса multimap определены следующие опера-
торы сравнения:
■■ ==
■■ <
■■ <=
■■ !=
■■ >
■■ >=
Класс multimap содержит перечисленные ниже функции-члены. В приведенных описаниях элемент key_type
представляет тип ключа, а элемент value_type — пару
элементов pair<Key, T>.
iterator begin();
const_iterator begin() const;
Возвращает итератор для первого элемента в мультиотображении.
void clear();
Удаляет все элементы из мультиотображения.
size_type count(const key_type &k) const;
Возвращает число вхождений ключа k в мультиотображении (1 или 0).
bool empty() const;
Возвращает значение true, если данное мультиотображение пустое, и false в противном случае.
const_iterator end() const;
iterator end();
Возвращает итератор, указывающий на конец мультиотображения.
pair<iterator, iterator> equal_range(const key_type &k);
pair<const_iterator, const_iterator>
equal_range(const key_type &k) const;
Возвращает пару итераторов, которые указывают
на первый и последний элементы в мультиотображении,
содержащие заданный ключ.
void erase(iterator i);
Удаляет элемент, адресуемый итератором i.
void erase(iterator start, iterator end);
Удаляет элементы в диапазоне, задаваемом параметрами start и end.
size_type erase(const key_type &k);
Удаляет из мультиотображения элементы, ключи
которых имеют значение k.
iterator find(const key_type &k);
const_iterator find(const key_type &k) const;
Возвращает итератор для заданного ключа. Если ключ
не обнаружен, возвращает итератор до конца мультиотображения.
allocator_type get_allocator() const;
Возвращает распределитель мультиотображения.
iterator insert(iterator i, const value_type &val);
Вставляет значение val после элемента, заданным итератором i, возвращает итератор для этого элемента.
template <class InIter> void insert(InIter start,
InIter end);
Вставляет элементы заданного диапазона.
pair<iterator, bool> insert(const value_type &val);
Вставляет значение val в используемое мультиотображение. Возвращает итератор для данного мультиотображения. Элемент вставляет только в том случае, если его
еще нет в мультиотображении. Если элемент был вставлен
возвращает пару pair<iterator, true>, в противном случае
pair<iterator, false>
key_compare key_comp() const;
Возвращает объект-функцию, которая сравнивает
ключи.
iterator lower_bound(const key_type &k);
const_iterator lower_bound(const key_type &k) const;
Возвращает итератор для первого элемента в мультиотображении, ключ которого равен значению k или больше
этого значения.
size_type max_size() const;
Возвращает максимальное число элементов, которое
может содержать мультиотображение.
reference operator[](const key_type &i);
Возвращает ссылку на элемент, заданный параметром i. Если этого элемента не существует, вставляет его
в мультиотображение.
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
Возвращает реверсивный итератор для конца мультиотображения.
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
Возвращает реверсивный итератор для начала мультиотображения.
size_type size() const;
Возвращает текущее количество элементов в мультиотображении.
void swap(multimap<Key, T, Comp, Allocator> &ob);
Выполняет обмен элементами данного мультиотображения и мультиотображения ob.
iterator upper_bound(const key_type &k);
const_iterator upper_bound(const key_type &k) const;
Возвращает итератор для первого элемента в мультиотображении, ключ которого больше заданного значения k.
value_compare value_comp() const;
Возвращает объект-функцию, которая сравнивает
значения.


*/


//Шаблонная функция для вывода содержимого

//template<class container>
//void Show(container col)
//{
//	for (auto i = col.begin(); i != col.end(); ++i)
//	{
//		cout << i->first << " " << i->second << "\n";
//	}
//	cout << "\n\n";
//
//
//}


class AddNumberFrom
{
	int delta;
	int current;
public:

	AddNumberFrom(int number, int from = 0) :delta(number), current(from) {};

	int operator ()()
	{
		cout << current << " * " << delta<<" = \n";
		return current += delta;
	}

};



//bool isEvan(int num)
//{
//	return bool(num % 2);
//}


int main()
{
	setlocale(LC_ALL,"Rus");

	/*
	//cout << "Map\n\n";
	////Создаем пустой контейнер (отображение)
	//
	//map<string, int> cont;
	////Создаем пустой контейнер (мультиотображение)

	//multimap<string, int> multicont;
	////Добавляем две пары в отображение
	//
	//cont.insert(pair<string, int>("Rybin", 600));
	//cont.insert(pair<string, int>("Tarasow", 2160));
	////Добавление пары
	//
	//cont["Sidorov"] = 30;
	//Show(cont);

	////Элемент не добавляется т.к ключ Rybin уже есть
	//cont.insert(pair<string, int>("Rybin", 1000));
	//Show(cont);

	//cout << "\nMultimap\n\n";
	//multicont.insert(pair<string, int>("Rybin", 60000));
	//multicont.insert(pair<string, int>("Tarasow", 100));
	//multicont.insert(pair<string, int>("Sidorov", 30));
	////Для мульти отображения не определен оператор []
	////	multicont["Sidorov"] = 30; ==ERROR!
	//Show(multicont);
	////Добавляем пару(Rybin,60000)
	//multicont.insert(pair<string, int>("Rybin", 600));
	//Show(multicont);
	////Ищем первое вхождение элемента с ключом "Tarasow"

	//multimap<string, int> ::iterator iter = multicont.find("Tarasow");
	//cout << iter->first << " " << iter->second << "\n\n";
	//cout << "Количество ключей 'Rybin' в multimap=  " << multicont.count("Rybin")<<"\n";
	//iter = multicont.lower_bound("Rybin");
	//for (; iter != multicont.upper_bound("Rybin") && iter != multicont.end(); iter++)
	//{
	//	cout << iter->first << " " << iter->second << "\n";
	//}
	//cout << "\n\n";

	*/

	cout << "\nТаблица умножения: \n\n";
	for (int i = 0; i <= 10; i++)
	{
		vector<int> l(10);
		generate_n(l.begin(), l.size(), AddNumberFrom(i));
		copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	}

	

	//list<int> l;
	//list<int>::iterator t;
	//for (int i = 1; i <= 10; i++)
	//{
	//	l.push_back(i);
	//}
	//copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	//cout << "\n\n";
	//t = remove_if(l.begin(), l.end(), isEvan);
	//copy(l.begin(),t, ostream_iterator<int>(cout, " "));



	return 0;
}