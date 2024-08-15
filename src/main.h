/*
 * Copyright (C) 2014 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MAIN_H
#define MAIN_H

#define PLUGIN_VERSION "1.4"

#define GLOBAL_VARTYPE_NONE (0)
#define GLOBAL_VARTYPE_INT (1)
#define GLOBAL_VARTYPE_STRING (2)
#define GLOBAL_VARTYPE_FLOAT (3)

#include <boost/unordered_map.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/variant.hpp>

#include <sdk/plugin.h>

#include <queue>
#include <string>

#define CHECK_PARAMS(m, n) \
	if (params[0] != (m * 4)) \
	{ \
		logprintf("*** %s: Expecting %d parameter(s), but found %d", n, m, params[0] / 4); \
		return 0; \
	}

typedef boost::unordered_map<std::string, boost::tuple<int, boost::variant<int, std::string, float> > > DataMap;
typedef boost::unordered_map<int, boost::tuple<int, std::queue<int> > > IndexMap;
typedef boost::unordered_map<std::string, DataMap::iterator> IteratorMap;
typedef boost::unordered_map<int, DataMap> MainMap;

typedef void (*logprintf_t)(const char*, ...);

extern logprintf_t logprintf;
extern void *pAMXFunctions;

#endif
