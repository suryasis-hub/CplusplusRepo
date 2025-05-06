/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <functional>
#include <iostream>


class Scheduler
{
    private:
        std::vector<std::function<int()>> listOfTasks;
    public:
        void addListOfTasks(std::function<int()> func)
        {
            listOfTasks.emplace_back(func);
        }
        
        void executeTasks()
        {
            for(auto& fun : listOfTasks)
            {
                int errorCode = fun();
                std::cout<<errorCode<<std::endl;
            }
        }
    
};

int functionOfAns()
{
    std::cout << "Task 2\n";
    return 2;
}

int main()
{
    Scheduler scheduler;
    scheduler.addListOfTasks([]() 
        {
            std::cout << "Task 1\n";
            return 1;
        }
    );
    scheduler.addListOfTasks(functionOfAns);
    scheduler.executeTasks();

    return 0;
}
