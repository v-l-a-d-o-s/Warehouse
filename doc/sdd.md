# Документ проектування

## Архітектура
3-рівнева:
- Презентація  
- Бізнес-логіка
- Дані
`

## Компоненти
- Модуль вводу/виводу
- Управління товарами
- Сховище даних

## Потоки даних
Основні сценарії:
- Додавання товару  
- Пошук товару
   - Зчитування даних зі сховища
   - Фільтрація даних
   - Вивід результатів

## Сховище даних
- Формат даних: CSV текстовий файл
- Структура: 
   id | Назва | Ціна | Кількість