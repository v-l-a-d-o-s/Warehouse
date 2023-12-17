# Мінімальна підтримувана версія CMake
cmake_minimum_required(VERSION 3.5)

# Назва проекту та мова
project(warehouse LANGUAGES C++) 

# Список джерельних файлів
set(SOURCES
  src/main.cpp
  src/warehouse.cpp
  src/product.cpp 
  src/product_repository.cpp
)

# Додати виконуваний файл з джерелами  
add_executable(main ${SOURCES})  

# Додати папки з хедер-файлами в розшук
target_include_directories(main PUBLIC include)
