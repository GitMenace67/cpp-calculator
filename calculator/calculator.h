    #pragma once
    #include <string>

    using Number = double;


    // Реализуйте здесь класс Calculator.

    class Calculator{
    public:
        void Set(Number n);
        Number GetNumber() const;
        void Add(Number n);
        void Sub(Number n);
        void Div(Number n);
        void Mul(Number n);
        void Pow(Number n);
        void Save();
        void Load();
        bool HasMem() const;
        std::string GetNumberRepr() const;

    private:
        Number current_num_=0;
        Number mem_=0;
        bool mem_empty_=true;

    };

    // Разместите тут реализацию класса Calculator из вашего решения
    // задания темы «Классы».