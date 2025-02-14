<h1 align="center">¡Hola! 👋 Soy Miguel</h1>

# Get Next Line
## 📝 Descripción
Get Next Line (GNL) es una función que lee una línea de texto desde un descriptor de archivo. La función devuelve la línea que se acaba de leer, o NULL si se ha alcanzado el final del archivo o si ocurrió un error.

## 🔍 Funcionamiento Detallado

### Prototipo de la función
```c
char *get_next_line(int fd);
```

### Parámetros
- `fd`: El descriptor de archivo desde donde leer.
- Retorna: La línea leída o NULL si no hay nada más que leer o si ocurrió un error.

### Estructura del Proyecto
```
.
├── get_next_line.c     # Función principal
├── get_next_line.h     # Header con prototipos y definiciones
└── get_next_line_utils.c # Funciones auxiliares
```

### Funciones Principales

1. `get_next_line()`: Función principal que:
   - Valida el descriptor de archivo y BUFFER_SIZE
   - Gestiona la lectura del archivo
   - Mantiene el texto restante entre llamadas
   - Retorna la siguiente línea

2. `read_and_store()`: 
   - Lee el archivo usando BUFFER_SIZE
   - Concatena los datos leídos
   - Continúa hasta encontrar un '\n' o EOF

3. `extract_line()`:
   - Extrae la línea hasta el '\n'
   - Guarda el resto para la siguiente llamada

### Variables Estáticas
- `stored_text`: Almacena el texto restante entre llamadas a la función

### Gestión de Memoria
- Todas las asignaciones de memoria son liberadas apropiadamente
- No hay fugas de memoria (memory leaks)
- Se manejan correctamente los errores de malloc

## 🚀 Uso

### Compilación
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

### Ejemplo de Uso
```c
int fd = open("archivo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## ⚠️ Consideraciones
- BUFFER_SIZE puede ser modificado en tiempo de compilación
- La función maneja correctamente múltiples descriptores de archivo
- Compatible con archivos de texto y binarios
- Gestiona correctamente los errores de lectura

## 🔧 Limitaciones
- No debe tener memory leaks
- Solo se permiten las siguientes funciones:
  - read()
  - malloc()
  - free()
- Variable estática limitada a 1

## 📚 Funciones Auxiliares

### ft_strdup()
- Crea una copia de una cadena
- Gestiona la memoria dinámicamente

### ft_strjoin()
- Concatena dos cadenas
- Retorna una nueva cadena

### ft_strchr()
- Busca un carácter en una cadena
- Retorna un puntero a la primera ocurrencia

### ft_substr()
- Extrae una subcadena
- Gestiona la memoria para la nueva cadena

## 🧪 Testing
```bash
# Compilar con diferentes tamaños de buffer
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 *.c
```

## 📈 Rendimiento
El rendimiento depende del BUFFER_SIZE establecido:
- BUFFER_SIZE pequeño = Más llamadas a read()
- BUFFER_SIZE grande = Menos llamadas a read() pero más uso de memoria

---


- LinkedIn: https://www.linkedin.com/in/miguelfdezmunoz

---

Nota: Este repositorio se sube con el propósito de compartir mi progreso y ofrecer un recurso orientativo para aquellos que necesiten ayuda en su aprendizaje. Espero que se utilice como base de estudio y no solo para copiar y pegar soluciones.
<p align="center">🚀 Never stop learning!</p>
