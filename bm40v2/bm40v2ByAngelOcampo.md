# Configuración de Teclado QMK — BM40HS RGB (rev2)

**Usuario:** Angel Ocampo (Fullstack Developer)  
**Stack Principal:** Laravel, Vue.js, PHP, JavaScript, Firebird SQL Redacción
**Hardware:** KpRepublic BM40HS RGB V2 · Ortholineal 40% · Interruptores Silent Black  · Ley Caps XDA · Case Aglomerado forrado con fibra de carbono y soporte de polipropileno 
**Firmware:** QMK

---

## 1. Arquitectura de Capas

El teclado opera bajo una lógica de 5 capas dinámicas para maximizar la eficiencia en un formato reducido de 47 teclas.

| Capa | Nombre | Activación | Función Principal |
| :--- | :--- | :--- | :--- |
| **0** | `_QWERTY` | Base | Escritura estándar. Incluye `LT(_DIRECTION, KC_F)` en la tecla F. |
| **1** | `_LOWER` | `TL_LOWR` (MO) | Símbolos de programación, macros de Laravel/Vue y atajos de VS Code. |
| **2** | `_RAISE` | `TL_UPPR` (MO) | Teclado numérico, teclas de función F1–F12 y operadores aritméticos. |
| **3** | `_ADJUST` | Lower + Raise | Configuración RGB, controles de mouse y reset de firmware. |
| **4** | `_DIRECTION` | Hold `F` | Navegación rápida de documentos (Home, End, PgUp, PgDn, flechas). |

---

## 2. Definiciones de Teclas Personalizadas (Custom Keycodes)

### Smart Keys — Auto-completado de pares

| Keycode | Output | Descripción |
| :--- | :--- | :--- |
| `S_BRC` | `[]` + cursor | Par de corchetes con cursor posicionado al centro. |
| `S_PAR` | `()` + cursor | Par de paréntesis con cursor posicionado al centro. |
| `S_CUR` | `{}` + cursor | Par de llaves con cursor posicionado al centro. |

### Macros de Productividad (PHP / JS / Laravel / Vue)

| Keycode | Output | Uso típico |
| :--- | :--- | :--- |
| `M_ASIG` | `=> ` | Operador fat arrow · callbacks, arrow functions, arrays asociativos PHP. |
| `M_ARRO` | `->` | Operador de acceso a objetos y encadenamiento de métodos en Laravel. |
| `VS_JOIN` | `Ctrl+Shift` | Alias físico para combos de VS Code (ej. `Ctrl+Shift+P`, `Ctrl+Shift+K`). |

---

## 3. Mapas de Teclas (Layouts)

> **Leyenda:** Las celdas vacías (`···`) indican teclas transparentes que heredan la capa inferior. Las teclas resaltadas en negrito son modificadores de capa.

### Capa 0 — `_QWERTY` (Base)

| `Esc` | Q | W | E | R | T | Y | U | I | O | P | `Bksp` |
|---|---|---|---|---|---|---|---|---|---|---|---|
| `Tab` | A | S | D | `LT(4,F)`¹ | G | H | J | K | L | `;` | `Enter` |
| `Shift` | Z | X | C | V | B | N | M | `,` | `.` | `/` | `"` |
| `Ctrl` | `Menu` | `GUI` | `Alt` | **`Lower`** | `Space` | `Space` | **`Raise`** | `Del` | `Shift` | `Home` | `End` |

> ¹ `LT(4,F)`: tap = `F`, hold = activa `_DIRECTION`.

---

### Capa 1 — `_LOWER` · Símbolos *(mantener Lower)*

| ··· | `/` | `\` | `S_BRC` | `M_ASIG` | `` ` `` | `^` | `-` | `_` | `~` | `Del` | `Bksp` |
|---|---|---|---|---|---|---|---|---|---|---|---|
| `Caps` | ··· | `$` | `S_PAR` | `M_ARRO` | `PrtSc` | `%` | `<` | `>` | `*` | ··· | `Enter` |
| ··· | `#` | `@` | `S_CUR` | `VS_JOIN` | ··· | ··· | `&` | `\|` | `!` | ··· | ··· |
| ··· | ··· | ··· | ··· | **`Lower`** | `Space` | `Space` | **`Raise`** | ··· | ··· | ··· | ··· |

> - `` ` `` (backtick): template literals JS, bloques de código Markdown.
> - `$`: acceso a variables PHP y selectores JS/Vue.
> - `PrtSc`: captura de pantalla, útil para documentación.

---

### Capa 2 — `_RAISE` · Números y Funciones *(mantener Raise)*

| ··· | ··· | `F3` | `F4` | `F9` | `.` | `+` | `1` | `2` | `3` | `-` | `Bksp` |
|---|---|---|---|---|---|---|---|---|---|---|---|
| ··· | ··· | `F2` | `F5` | `F12` | `,` | `+` | `4` | `5` | `6` | `*` | `Enter` |
| ··· | ··· | `F1` | `F11` | ··· | ··· | `/` | `7` | `8` | `9` | `=` | `Del` |
| ··· | ··· | ··· | ··· | **`Lower`** | `Space` | `Space` | **`Raise`** | `0` | ··· | ··· | ··· |

> - Bloque numérico distribuido: 1–6 en fila superior derecha, 7–9 en fila media, `0` en thumb row.
> - F1–F12 accesibles sin abandonar home row.
> - Operadores aritméticos `+`, `-`, `*`, `/`, `=` disponibles para expresiones.

---

### Capa 3 — `_ADJUST` · RGB y Mouse *(mantener Lower + Raise)*

| `Br+` | `Mode+` | `Hue+` | `Sat+` | `Spd+` | `Br+` | ··· | `ClicL` | `↑` | `ClicR` | ··· | `Mute` |
|---|---|---|---|---|---|---|---|---|---|---|---|
| `Br-` | `Mode-` | `Hue-` | `Sat-` | `Spd-` | `Br-` | ··· |`←` | `↓` | `→` | ··· | `Vol-` |
| ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | `Vol+` |
| `RGB` | ··· | ··· | ··· | **`Lower`** | `Space` | `Space` | **`Raise`** | ··· | ··· | `Reset` | ··· |

> - Control de RGB: brillo (`Br`), modo, matiz (`Hue`), saturación (`Sat`), velocidad (`Spd`).
> - Mouse integrado: movimiento con flechas, clic izquierdo y derecho.
> - `Reset`: entra en modo bootloader para flashear nuevo firmware sin abrir el teclado.
> - `RGB`: toggle de iluminación on/off.

---

### Capa 4 — `_DIRECTION` · Navegación *(hold F)*

| ··· | ··· | `PgUp` | `Home` | ··· | ··· | `PgDn` | `End` | `↑` | ··· | ··· | `Bksp` |
|---|---|---|---|---|---|---|---|---|---|---|---|
| ··· |··· | `Shift` | `Ctrl` | **`[F]`** | ··· | ··· | `←` | `↓` | `→` | ··· | `Enter` |
| ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· | ··· |
| ··· | ··· | ··· | ··· | **`Lower`** | `Space` | `Space` | **`Raise`** | ··· | ··· | ··· | ··· |

> - Inspirado en navegación estilo Vim: flechas bajo la mano derecha en posición natural.
> - `Shift` y `Ctrl` en mano izquierda permiten combos de selección simultáneos:
>   - `Ctrl + →` · salto de palabra
>   - `Shift + →` · selección carácter a carácter
>   - `Ctrl + Shift + →` · selección de palabra completa
> - `Home` / `End` / `PgUp` / `PgDn` sin mover la mano de home row.

---

## 4. Activación de Capas — Resumen

| Capa | Activación |
| :--- | :--- |
| `_QWERTY` | Siempre activa (base) |
| `_LOWER` | Mantener `Lower` |
| `_RAISE` | Mantener `Raise` |
| `_ADJUST` | Mantener `Lower` **+** `Raise` simultáneamente |
| `_DIRECTION` | Mantener `F` (tap sigue siendo `F`) |

---

## 5. Sistemas Operativos

| OS | Notas |
| :--- | :--- |
| **Windows** | Layout principal. GUI = Win key. |
| **Linux** | GUI = Super key. Sin cambios adicionales en firmware. |

---

*Última actualización: junio 2026*
