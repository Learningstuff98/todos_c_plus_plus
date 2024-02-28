#include <iostream>
#include <vector>

void greet_user() {
  std::cout << "Please enter one of the following todo operations:" << std::endl;
  std::cout << "add, list, edit, delete or exit." << std::endl;
};

std::string get_desired_operation() {
  greet_user();
  std::string desired_operation;
  std::cin >> desired_operation;
  return desired_operation;
};

std::string get_todo() {
  std::cout << "Please enter a new todo" << std::endl;
  std::string new_todo;
  std::cin >> new_todo;
  return new_todo;
}

void list_todos(std::vector<std::string> const &todos) {
  std::cout << "\n";
  std::cout << "-------------------------" << std::endl;
  std::cout << "The current todos are as follows:" << std::endl;
  for(auto todo: todos) {
    std::cout << todo << std::endl;
  }
  std::cout << "-------------------------\n\n";
};

int main() {
  std::vector<std::string> todos {};
  std::string desired_operation {get_desired_operation()};
  while(desired_operation != "exit") {
    if(desired_operation == "add") {
      todos.push_back(get_todo());
      desired_operation = get_desired_operation();
    }
    if(desired_operation == "list") {
      list_todos(todos);
      desired_operation = get_desired_operation();
    }
  }
  std::cout << "Program shutting down. Goodbye.";
  return 0;
};
