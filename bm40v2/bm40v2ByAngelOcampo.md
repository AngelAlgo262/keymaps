# Configuración de Teclado QMK - BM40HS RGB (rev2)
**Usuario:** Angel Ocampo (Fullstack Developer)  
**Stack Principal:** Laravel, Vue.js, PHP, JS, Firebird SQL.  
**Hardware:** BM40HS RGB (Ortholineal 40%) con interruptores Silent Black.

## 1. Arquitectura de Capas
El teclado opera bajo una lógica de 5 capas dinámicas para maximizar la eficiencia en un formato reducido de 47 teclas.

| Capa | Nombre | Activación | Función Principal |
| :--- | :--- | :--- | :--- |
| **0** | `_QWERTY` | Base | Escritura estándar. Incluye `LT(_DIRECTION, KC_F)` en la tecla F. |
| **1** | `_LOWER` | `TL_LOWR` (MO) | Símbolos de programación, Macros de Laravel y Atajos de VS Code. |
| **2** | `_RAISE` | `TL_UPPR` (MO) | Teclado numérico, teclas de función F1-F12 y navegación. |
| **3** | `_ADJUST` | Lower + Raise | Configuración de iluminación RGB, controles de Mouse y Reset. |
| **4** | `_DIRECTION`| Hold 'F' | Navegación rápida de documentos (Home, End, PgUp, PgDn). |

## 2. Definiciones de Teclas Personalizadas (Custom Keycodes)
Para optimizar el desarrollo en **Laravel** y **Vue**, se han programado comportamientos lógicos en el firmware:

### Smart Keys (Auto-completado de pares)
* **S_BRC (`[]`):** Genera el par de corchetes y posiciona el cursor en medio.
* **S_PAR (`()`):** Genera el par de paréntesis y posiciona el cursor en medio.
* **S_CUR (`{}`):** Genera el par de llaves y posiciona el cursor en medio.

### Macros de Productividad (PHP/JS)
* **M_ASIG (`=> `):** Operador de asignación para arreglos y colecciones.
* **M_ARRO (`->`):** Operador de acceso a objetos y métodos.
* **VS_JOIN (`Ctrl + Shift`):** Alias físico para ejecutar comandos combinados en VS Code.

## 3. Mapas de Teclas (Layouts)

### Capa 0: QWERTY (Principal)

| | | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|---|
| `Esc` | Q | W | E | R | T | Y | U | I | O | P | `Bksp` |
| `Tab` | A | S | D | F | G | H | J | K | L | `;` | `Enter` |
| `Shift` | Z | X | C | V | B | N | M | `,` | `.` | `/` | `"` |
| `Ctrl` | Menu | GUI | `Alt` | **Lower** | `Space` | `Space` | **Raise** | `Del` | `Shift` | `Home` | `End` |

---

## Capa 1: LOWER · Símbolos *(mantener Lower)*

| | | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|---|
| | `/` | `\` | `[]` | `=>` | `` ` `` | `^` | `-` | `_` | `~` | `Del` | `Bksp` |
| `Caps` | | `$` | `()` | `->` | `PtrSc` | `%` | `<` | `>` | `*` | | `Enter` |
| | `#` | `@` | `{}` | | **Lower** | `Space` | **Raise** | | `&` | `\|` | `!` |

---