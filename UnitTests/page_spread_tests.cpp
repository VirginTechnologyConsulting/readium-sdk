//
//  page_spread_tests.cpp
//  ePub3
//
//  Created by Jim Dovey on 2013-05-27.
//  Copyright (c) 2012-2013 The Readium Foundation and contributors.
//  
//  The Readium SDK is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <ePub3/container.h>
#include <ePub3/package.h>
#include <ePub3/spine.h>
#include "catch.hpp"

#define EPUB_PATH "TestData/page-blanche.epub"

using namespace ePub3;

TEST_CASE("Page spread comes back correctly", "")
{
    ContainerPtr c = Container::OpenContainer(EPUB_PATH);
    PackagePtr pkg = c->DefaultPackage();
    
    SpineItemPtr item = pkg->FirstSpineItem();
    REQUIRE(item->Spread() == PageSpread::Right);
    
    item = item->Next();
    REQUIRE(item->Spread() == PageSpread::Left);
}
