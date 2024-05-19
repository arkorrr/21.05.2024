#include <iostream>
using namespace std;

class Singleton 
{
private:
    //указатель на единственный экземпляр класса
    static Singleton* Boss;
    int k;
    //закрытый конструктор
    Singleton(int i) {
        k = i;
    }
public:
    //функция для получения указателя на
    //единственный экземпляр класса
    static Singleton* getReference()
    {
        cout << "Boss was created" << endl;
        return Boss;
    }
    static Singleton* deleteReference()
    {
        delete Boss;
        Boss = NULL;
        cout << endl;
        cout << "Boss was destroyed" << endl;
        return Boss;
    }
    //получение значения нестатического члена класса
    int getValue()
    {
        return k;
    }
    //перезапись значения нестатического члена класса
    void setValue(int i)
    {
        k = i;
    }
    void SkillsBoss()
    {
        while (true)
        {
            int buffer;
            cout << "Enter 1, if you want to getValue" << endl;
            cout << "Enter 2, if you want to setValue" << endl;
            cout << "Enter 3, if you want to destroy Boss" << endl;
            cin >> buffer;
            switch (buffer)
            {
            case 1:
                cout << "Value = " << getValue() << endl;
                break;
            case 2:
                int buf;
                cout << "Enter value which you want to set: ";
                cin >> buf;
                setValue(buf);
                break;
            case 3:
                deleteReference();
                return;
            default:
                cout << "Invalid choice. " << endl;
                break;
            }
        }
    }
};

Singleton* Singleton::Boss = new Singleton(1);

int main()
{
    Singleton* a = Singleton::getReference();
    //работа с компонентом объекта
    cout << a->getValue() << "\n\n";
    a->setValue(a->getValue() + 5);
    cout << a->getValue() << endl;
    a->SkillsBoss();

    a = Singleton::deleteReference();
     
}

// Шаблон Singleton обеспечивает создание только одного экземпляра класса.
// Используется закрытый конструктор!
// Этот конструктор вызывается единожды при обязательной инициализации статического поля класса
// Закрытый конструктор можно вызвать, так как инициализация стат. поля происходит внутри класса