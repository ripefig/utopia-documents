/*****************************************************************************
 *  
 *   This file is part of the Utopia Documents application.
 *       Copyright (c) 2008-2017 Lost Island Labs
 *           <info@utopiadocs.com>
 *   
 *   Utopia Documents is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU GENERAL PUBLIC LICENSE VERSION 3 as
 *   published by the Free Software Foundation.
 *   
 *   Utopia Documents is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 *   Public License for more details.
 *   
 *   In addition, as a special exception, the copyright holders give
 *   permission to link the code of portions of this program with the OpenSSL
 *   library under certain conditions as described in each individual source
 *   file, and distribute linked combinations including the two.
 *   
 *   You must obey the GNU General Public License in all respects for all of
 *   the code used other than OpenSSL. If you modify file(s) with this
 *   exception, you may extend this exception to your version of the file(s),
 *   but you are not obligated to do so. If you do not wish to do so, delete
 *   this exception statement from your version.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with Utopia Documents. If not, see <http://www.gnu.org/licenses/>
 *  
 *****************************************************************************/

#ifndef SHAREDCLASS_H
#define SHAREDCLASS_H

#include <cinema6/config.h>

namespace CINEMA6
{

    template< class SharedClass >
    class LIBCINEMA_API Singleton
    {
    public:
        // Constructor
        Singleton()
        {
            // Instantiate if necessary
            if (count == 0)
            {
                instance = new SharedClass;
            }
            // Inc ref count
            ++count;
        }
        // Destructor
        ~Singleton()
        {
            // Dec ref count
            --count;
            // Destroy if necessary
            if (count == 0)
            {
                delete instance;
                instance = 0;
            }
        }

        int instanceRefCount() const
        {
            return count;
        }

        // Singleton accessor
        SharedClass & operator () ()
        {
            return *instance;
        }

    private:
        static SharedClass * instance;
        static int count;

    }; // class Singleton


    template< class SharedClass >
    SharedClass * Singleton< SharedClass >::instance = 0;

    template< class SharedClass >
    int Singleton< SharedClass >::count = 0;
}

#endif // SHAREDCLASS_H
