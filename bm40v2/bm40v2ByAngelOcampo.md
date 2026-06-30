# Configuración de Teclado QMK — BM40HS RGB (rev2)

**Usuario:** Angel Ocampo (Fullstack Developer)  
**Stack Principal:** Laravel, Vue.js, PHP, JavaScript, Firebird SQL, Redacción  
**Hardware:** KpRepublic BM40HS RGB V2 · Ortholineal 40% · Interruptores Silent Black · Keycaps XDA · Case Aglomerado forrado con fibra de carbono y soporte de polipropileno  
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

| Keycode | Activación | Output | Uso típico |
| :--- | :--- | :--- | :--- |
| `M_ASIG` | `Lower` + `R` | `=> ` | Operador fat arrow · callbacks, arrow functions, arrays asociativos PHP. |
| `M_ARRO` | `Lower` + `F` | `->` | Operador de acceso a objetos y encadenamiento de métodos en Laravel. |
| `M_DD` | `Lower` + `V` | `dd();` + cursor | Debug helper de Laravel con cursor dentro de los paréntesis. |
| `M_LOG` | `Lower` + `B` | `console.log()` + cursor | Debug helper de JS con cursor dentro de los paréntesis. |

---

## 3. Mapas de Teclas (Layouts)

> **Leyenda:** `···` = tecla transparente que hereda la capa inferior. Las teclas en negrito son modificadores de capa.  
> El espaciador físico es una tecla **2u** (ocupa dos columnas).

### Capa 0 — `_QWERTY` (Base)

<table>
<tr>
  <td><code>Esc</code></td><td>Q</td><td>W</td><td>E</td><td>R</td><td>T</td>
  <td>Y</td><td>U</td><td>I</td><td>O</td><td>P</td><td><code>Bksp</code></td>
</tr>
<tr>
  <td><code>Tab</code></td><td>A</td><td>S</td><td>D</td><td><code>LT(4,F)</code>¹</td><td>G</td>
  <td>H</td><td>J</td><td>K</td><td>L</td><td><code>;</code></td><td><code>Enter</code></td>
</tr>
<tr>
  <td><code>Shift</code></td><td>Z</td><td>X</td><td>C</td><td>V</td><td>B</td>
  <td>N</td><td>M</td><td><code>,</code></td><td><code>.</code></td><td><code>/</code></td><td><code>"</code></td>
</tr>
<tr>
  <td><code>Ctrl</code></td><td><code>Menu</code></td><td><code>GUI</code></td><td><code>Alt</code></td>
  <td><strong><code>Lower</code></strong></td><td colspan="2"><strong><code>Space (2u)</code></strong></td>
  <td><strong><code>Raise</code></strong></td><td><code>Del</code></td><td><code>Shift</code></td><td><code>Home</code></td><td><code>End</code></td>
</tr>
</table>

> ¹ `LT(4,F)`: tap = `F`, hold = activa `_DIRECTION`.

---

### Capa 1 — `_LOWER` · Símbolos *(mantener Lower)*

<table>
<tr>
  <td>···</td><td><code>/</code></td><td><code>\</code></td><td><code>S_BRC</code></td><td><code>M_ASIG</code></td><td><code>`</code></td>
  <td><code>^</code></td><td><code>-</code></td><td><code>_</code></td><td><code>~</code></td><td><code>Del</code></td><td><code>Bksp</code></td>
</tr>
<tr>
  <td><code>Caps</code></td><td><code>=</code></td><td><code>$</code></td><td><code>S_PAR</code></td><td><code>M_ARRO</code></td><td><code>PrtSc</code></td>
  <td><code>%</code></td><td><code>&lt;</code></td><td><code>&gt;</code></td><td><code>*</code></td><td>···</td><td><code>Enter</code></td>
</tr>
<tr>
  <td>···</td><td><code>#</code></td><td><code>@</code></td><td><code>S_CUR</code></td><td><code>M_DD</code></td><td><code>M_LOG</code></td>
  <td>···</td><td><code>&amp;</code></td><td><code>|</code></td><td><code>!</code></td><td>···</td><td>···</td>
</tr>
<tr>
  <td>···</td><td>···</td><td>···</td><td>···</td>
  <td><strong><code>Lower</code></strong></td><td colspan="2"><strong><code>Space (2u)</code></strong></td>
  <td><strong><code>Raise</code></strong></td><td>···</td><td>···</td><td>···</td><td>···</td>
</tr>
</table>

> - `` ` `` (backtick): template literals JS, bloques de código Markdown.
> - `$` y `=`: variables PHP y comparaciones.
> - `M_DD` (`Lower`+`V`): inserta `dd();` con cursor dentro — debug rápido en Laravel.
> - `M_LOG` (`Lower`+`B`): inserta `console.log()` con cursor dentro — debug rápido en JS/Vue.
> - `PrtSc`: captura de pantalla, útil para documentación.

---

### Capa 2 — `_RAISE` · Números y Funciones *(mantener Raise)*

<table>
<tr>
  <td>···</td><td>···</td><td><code>F3</code></td><td><code>F4</code></td><td><code>F9</code></td><td><code>.</code></td>
  <td><code>+</code></td><td><code>1</code></td><td><code>2</code></td><td><code>3</code></td><td><code>-</code></td><td><code>Bksp</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td><code>F2</code></td><td><code>F5</code></td><td><code>F12</code></td><td><code>,</code></td>
  <td><code>:</code></td><td><code>4</code></td><td><code>5</code></td><td><code>6</code></td><td><code>*</code></td><td><code>Enter</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td><code>F1</code></td><td><code>F11</code></td><td>···</td><td>···</td>
  <td><code>/</code></td><td><code>7</code></td><td><code>8</code></td><td><code>9</code></td><td><code>=</code></td><td><code>Del</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td>···</td><td>···</td>
  <td><strong><code>Lower</code></strong></td><td colspan="2"><strong><code>Space (2u)</code></strong></td>
  <td><strong><code>Raise</code></strong></td><td><code>0</code></td><td>···</td><td>···</td><td>···</td>
</tr>
</table>

> - Bloque numérico: 1–6 fila superior derecha, 7–9 fila media, `0` en thumb row.
> - F1–F12 accesibles sin abandonar home row.
> - Operadores aritméticos `+`, `-`, `*`, `/`, `=` y separadores `.`, `,`, `:` disponibles.

---

### Capa 3 — `_ADJUST` · RGB y Mouse *(mantener Lower + Raise)*

<table>
<tr>
  <td><code>Br+</code></td><td><code>Mode+</code></td><td><code>Hue+</code></td><td><code>Sat+</code></td><td><code>Spd+</code></td><td><code>Br-</code></td>
  <td>···</td><td><code>ClicL</code></td><td><code>↑</code></td><td><code>ClicR</code></td><td>···</td><td><code>Mute</code></td>
</tr>
<tr>
  <td><code>Br-</code></td><td><code>Mode-</code></td><td><code>Hue-</code></td><td><code>Sat-</code></td><td><code>Spd-</code></td><td><code>Br+</code></td>
  <td>···</td><td><code>←</code></td><td><code>↓</code></td><td><code>→</code></td><td>···</td><td><code>Vol-</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td>···</td><td>···</td><td>···</td><td>···</td>
  <td>···</td><td>···</td><td>···</td><td>···</td><td>···</td><td><code>Vol+</code></td>
</tr>
<tr>
  <td><code>RGB</code></td><td>···</td><td>···</td><td>···</td>
  <td><strong><code>Lower</code></strong></td><td colspan="2"><strong><code>Space (2u)</code></strong></td>
  <td><strong><code>Raise</code></strong></td><td>···</td><td>···</td><td><code>Reset</code></td><td>···</td>
</tr>
</table>

> - Control RGB: brillo (`Br`), modo, matiz (`Hue`), saturación (`Sat`), velocidad (`Spd`).
> - Mouse integrado: movimiento con flechas, clic izquierdo y derecho.
> - `Reset`: entra en modo bootloader para flashear firmware sin abrir el teclado.
> - `RGB`: toggle de iluminación on/off.

---

### Capa 4 — `_DIRECTION` · Navegación *(hold F)*

<table>
<tr>
  <td>···</td><td>···</td><td><code>PgUp</code></td><td><code>Home</code></td><td>···</td><td>···</td>
  <td><code>PgDn</code></td><td><code>End</code></td><td><code>↑</code></td><td>···</td><td>···</td><td><code>Bksp</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td><code>Shift</code></td><td><code>Ctrl</code></td><td><strong><code>[F]</code></strong></td><td>···</td>
  <td>···</td><td><code>←</code></td><td><code>↓</code></td><td><code>→</code></td><td>···</td><td><code>Enter</code></td>
</tr>
<tr>
  <td>···</td><td>···</td><td>···</td><td>···</td><td>···</td><td>···</td>
  <td>···</td><td>···</td><td>···</td><td>···</td><td>···</td><td>···</td>
</tr>
<tr>
  <td>···</td><td>···</td><td>···</td><td>···</td>
  <td><strong><code>Lower</code></strong></td><td colspan="2"><strong><code>Space (2u)</code></strong></td>
  <td><strong><code>Raise</code></strong></td><td>···</td><td>···</td><td>···</td><td>···</td>
</tr>
</table>

> - Navegación estilo Vim: flechas bajo la mano derecha en posición natural.
> - `Shift` y `Ctrl` en mano izquierda permiten combos de selección simultáneos:
>   - `Ctrl` + `→` · salto de palabra
>   - `Shift` + `→` · selección carácter a carácter
>   - `Ctrl` + `Shift` + `→` · selección de palabra completa
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
