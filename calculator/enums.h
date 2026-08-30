#pragma once

#include <QHash>

enum class Operation {
    MULTIPLICATION,
    DIVISION,
    SUBTRACTION,
    ADDITION,
    POWER,
};

enum class ControlKey {
    EQUALS,     // Кнопка "Равно".
    CLEAR,      // Кнопка "C".
    MEM_SAVE,   // Кнопка "MS".
    MEM_LOAD,   // Кнопка "ML".
    MEM_CLEAR,  // Кнопка "MC".
    PLUS_MINUS, // Кнопка "+-".
    BACKSPACE,  // Кнопка "Стереть последний символ".
    EXTRA_KEY,  // Дополнительная экстра-кнопка.
};

enum class ControllerType {
    UINT8_T,
    INT,
    INT64_T,
    SIZE_T,
    DOUBLE,
    FLOAT,
    RATIONAL,
};

const QHash<QString, ControllerType> text_to_contrtype = {{QString("uint8_t"), ControllerType::UINT8_T},
                                                          {QString("int"), ControllerType::INT},
                                                          {QString("int64_t"), ControllerType::INT64_T},
                                                          {QString("size_t"), ControllerType::SIZE_T},
                                                          {QString("double"), ControllerType::DOUBLE},
                                                          {QString("float"), ControllerType::FLOAT},
                                                          {QString("rational"), ControllerType::RATIONAL}
};