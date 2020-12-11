/*
 * Волков Матвей Андреевич
Спроектировать простейший «графический» векторный редактор.
Требование к функционалу редактора:
•	создание нового документа
•	импорт документа из файла
•	экспорт документа в файл
•	создание графического примитива (согласно варианту задания)
•	удаление графического примитива
•	отображение документа на экране (печать перечня графических объектов и их характеристик в std::cout)
•	реализовать операцию undo, отменяющую последнее сделанное действие. Должно действовать для операций добавления/удаления фигур.

Требования к реализации:
•	Создание графических примитивов необходимо вынести в отдельный класс – Factory.
•	Сделать упор на использовании полиморфизма при работе с фигурами;
•	Взаимодействие с пользователем (ввод команд) реализовать в функции main;
Вариант: Прямоугольник, трапеция, ромб
*/

#include "document.h"

//нужно, чтобы было 2 одинаковых типа
#define yourTYPE double, double

int main() {
    std::ofstream fout;
    std::ifstream fin;

    TDocument<yourTYPE> doc;
    std::string s;
    while ((std::cout << "> ") && (std::cin >> s)) {
        if (s == "n") {
            doc.CreateNew();
            std::cout << "Created new document" << std::endl;
        }
        else if (s == "o") {
            std::cin >> s;
            fin.open(s, std::ios::in | std::ios::binary);
            if (!fin.is_open()) {
                std::cout << "No such file in directory" << std::endl;
                fin.close();
            }
            else {
                doc.LoadFromFile(fin);
                std::cout << "Loaded document from " << s << std::endl;
                fin.close();
            }
        }
        else if (s == "s") {
            std::cin >> s;
            fout.open(s, std::ios::in | std::ios::binary | std::ios::trunc);
            if (fout.is_open()) {
                std::cout << "Cannot open this file" << std::endl;
            }
            else {
                doc.SaveToFile(fout);
                std::cout << "Saved document to " << s << std::endl;
                fout.close();
            }
        }
        else if (s == "+") {
            size_t pos;
            unsigned short type;
            std::cin >> pos >> type;
            doc.Add(pos, type);
        }
        else if (s == "-") {
            size_t pos;
            std::cin >> pos;
            doc.Delete(pos);
        }
        else if (s == "p") {
            std::cout << "Printing document:" << std::endl;
            std::cout << doc;
        }
        else if (s == "u") {
            doc.Undo();
        }
        else if (s == "h") {
            std::cout << "> \'n\' - create new document" << std::endl;
            std::cout << "> \'o\' - open document" << std::endl;
            std::cout << "> \'s\' - save document" << std::endl;
            std::cout << "> \'+\' - add a figure\n"
                         "when you add figure:\nfirst - enter your position you want insert your figure\n"
                         "second - enter figure ID:\n"
                         "  1 - rhombus\n  2 - rectangle\n  3 - trapeze" << std::endl;
            std::cout << "> \'-\' - remove a figure\n"
                         "when you remove figure, enter your position you want to delete" << std::endl;
            std::cout << "> \'p\' - print document" << std::endl;
            std::cout << "> \'u\' - undo changes" << std::endl;
            std::cout << "> \'h\' - show this message" << std::endl;
        }

        else if(s == "e"){
            return 0;
        }
        else {
            std::cout << "Unknown command. Type \'h\' to show help" << std::endl;
        }
    }
    return 0;
}