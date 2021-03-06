#ifndef __PLANNER_HPP__
#define __PLANNER_HPP__

#include "display.hpp"
#include "keyword.hpp"
#include <iostream>
#include <string>

#define PERMS 0777
#define MAX_BUF_SIZE 256

typedef struct __date {
    int year;
    int month;
    int date;
} When;

class Todo {
  public:
    Todo();
    Todo(int year, int month, int date, std::string title);

    void inputEvent();
    void createEvent(Keyword &keyword);
    // void deleteEvent(int index);
    int getDate();
    int getYear();
    int getMonth();
    std::string getTitle();
    std::string getKeyword();

    void setDate(int year, int month, int date);
    void setTitle(std::string title);
    void setKeyword(std::string keyword);

  private:
    std::string category;
    When when;
    std::string title;
    std::string keyword;
};

enum plannerMenu {
    CREATE,
    DELETE,
    GOTODATE,
    PREVIOUS,
    KEYWORD,
};

bool is_stringEmpty(char *buf);

bool checkFileExists(std::string dirname);
int numOfEvents(int year, int month, int date);
int numOfIncompletEvents(int year, int month, int date);
void createEvent(int year, int month, int date);
std::string deleteEvent(int year, int month, int date, int index);
void printList(int year, int month, int date);
void gotoDate(int *year, int *month, int *date);

// void inputEvent(Todo todo);
void markEvent(int year, int month, int date, int index);
void plannerMenuCreate();
void plannerMenuGotoDate();
void plannerMenuDelete();
void plannerMenuPrevious();
void plannerMenuKeyword();

void printNothingToDo();

#endif
