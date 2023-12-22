#include "shell.h"

/**
 * get_executable_path - Retrieves the full path of an executable from the PATH
 * environment variable.
 * @executable_name: Name of the executable.
 * Return: Full path of the executable, or NULL if not found.
 */
char *get_executable_path(char *executable_name)
{
    char *path_env; /* PATH environment variable */
    char *path_copy; /* Copy of PATH environment variable */
    char *path_token; /* Tokenized path */
    char *result; /* Full path of executable */
    char full_path[1024]; /* Full path of executable */

    path_env = getenv("PATH"); /* Get PATH environment variable */

    if (path_env == NULL) /* If PATH is not set */
        return (NULL);

    path_copy = strdup(path_env); /* Make a copy of PATH */
    path_token = strtok(path_copy, ":"); /* Tokenize PATH */

    while (path_token) /* Loop through tokens */
    {
        /* Build full path */
        snprintf(full_path, sizeof(full_path), "%s/%s", path_token, executable_name);

        if (access(full_path, F_OK | X_OK) == 0)
        {
            result = strdup(full_path); /* Make a copy of full path */
            free(path_copy); /* Free copy of PATH */
            return (result);
        }
        path_token = strtok(NULL, ":"); /* Get next token */
    }
    free(path_copy);

    return (NULL);
}
