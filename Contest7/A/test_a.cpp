1. Ставь чаще пустые строки между логическими блоками,
а то монотонный код - плохочитаем
2. this->d_size; зачем? просто d_size 
this почти везде лишний
3. const_iterator begin() const и const_iterator cbegin() const
- копипаста, можно было сделать return cbegin(); в const_iterator begin() const
4. размеры и индексация - size_t 
5. убери в private всё что не должно торчать наружу 
6. а что с exception safety? Deque(const Deque& other)?
7. Deque& operator=(const Deque& other) 
copy and swap?
8. Deque<int>::iterator it; - у тебя CE 
9. длинные строки нужно переносить -
можешь использовать автоформатер
10. // mb TL here, fix later
чего)? 
11. При этом хранить в итераторе указатель на сам объект deque нельзя: разыменование итератора должно требовать в большинстве случаев лишь одного разыменования указателя
- у тебя стабильно 2 разыменования 
12. убери лишние комментарии из кода
13. bool operator==(const base_iterator& other) const = default;
14. operator> лучше выразить как обычно - через operator<