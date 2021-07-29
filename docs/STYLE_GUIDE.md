# Style Guide 🧶

- ### Banners should be formmated as follows:

```c++
/* file_directory/file_name.extension
 * File description.
 * copyright
 * author */
```

- ### User include directives should be included before library directives.

```c++
#include "user_file.h"
#include <library>
```

- ### ``using namespace`` should not be included in source files.

Wrong:

```c++
#include <iostream>

using std::cout;
```

Wrong:

```c++
#include <vector>

using namespace std;
```

- ### The ``main()`` function should have a return type.

- ### Curly braces should be placed on newlines.

```c++
int main()
{
    ...
}
```

- ### Definitions should occur at declarations.

```c++
int num = 12;
const int limit = 32;
```

``const`` should be west.

Right:

```c++
const int limit = 12;
```

Wrong:

```c++
int const limit = 12;
```

- ### Spaces should be included in expressions.

Right:

```c++
while (limit != 12)
{

}
```

Wrong:

```c++
while(limit!=12)
{

}
```

- ### New lines to the output stream should use ``std::endl;``.

- ### The ``main()`` function should return 0 at the end of execution.

- ### Do not include trailing new lines in source files.