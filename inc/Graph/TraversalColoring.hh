// Copyright (c) 2020 Norbert Rühl
//
// This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//
//     1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//
//     2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//
//     3. This notice may not be removed or altered from any source distribution.

#ifndef LIBNORB_DSA_TRAVERSALCOLORING_HH
#define LIBNORB_DSA_TRAVERSALCOLORING_HH

#include <unordered_map>
#include <memory>

namespace norbdsa
{
    enum class TraversalColor{
        White,
        Gray,
        Black
    };

    template < template <typename ,typename...> typename C,typename T,typename ... U> class TraversalColoring {
    private:
        std::unordered_map<std::shared_ptr< C<T,U...> > ,TraversalColor> Colors;
    public:
        void setMark(std::shared_ptr<C<T,U...>> F,TraversalColor Color=TraversalColor::White){
            Colors[F] = Color;
        }
        TraversalColor getMark(std::shared_ptr<C<T,U...>> F)
        {
            if(!Colors.contains(F))
            {
                return TraversalColor::White;
            }
            return Colors[F];
        }

    };
}

#endif //LIBNORB_DSA_TRAVERSALCOLORING_HH
