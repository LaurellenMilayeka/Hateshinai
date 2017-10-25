#pragma once

namespace Engine {

    class Vector2 {
    
    private:

        double _x;
        double _y;

    public:

        Vector2();
        Vector2(double, double);
        ~Vector2();

        double x() const;
        double y() const;

        static Vector2 Up();
        static Vector2 Down();
        static Vector2 Left();
        static Vector2 Right();

        Vector2& operator=(Vector2 const&);
        Vector2& operator+=(Vector2 const&);

        Vector2& operator*(double const);
    };
};