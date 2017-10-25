#pragma once

#include "Engine.hpp"
#include "Component.hpp"
#include "Texture.hpp"
#include "Vector2.hpp"
#include "Font.hpp"
#include "GameObject.hpp"

namespace Engine {

    class Label : public Component {

    private:

        std::string _label;
        Texture _labelTexture;
        Vector2 _relativePosition;
        Font _actualFont;

        bool _updated;
        bool _fontInit;
        bool _textInit;
        bool _texInit;

    public:

        Label() { }
        Label(GameObject&);
        virtual ~Label();

        static std::string GetType();
        std::string const& GetText() const;

        void Update();
        void Render();
        
        void SetText(std::string const&);
        void SetFont(std::string const&);
    };
};