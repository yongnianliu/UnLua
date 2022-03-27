// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#include "LuaContext.h"
#include "LuaEnv.h"
#include "UnLuaModule.h"

FLuaContext* GLuaCxt = nullptr;

/**
 * Create GLuaCxt
 */
FLuaContext* FLuaContext::Create()
{
    if (!GLuaCxt)
    {
        static FLuaContext Context;
        GLuaCxt = &Context;
    }
    return GLuaCxt;
}

FLuaContext::operator lua_State*() const
{
    const auto Env = IUnLuaModule::Get().GetEnv();
    return Env ? Env->GetMainState() : nullptr;
}
