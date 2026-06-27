# Ficha Técnica — KPRepublic BM40HS RGB (rev2)

La **KPRepublic BM40 v2** es una placa PCB de ingeniería avanzada diseñada para teclados mecánicos custom en formato **40%** con distribución **ortolineal** (estilo Planck). Destaca por su versatilidad, permitiendo montar un sistema ultra compacto, totalmente ergonómico y altamente personalizable para entornos de desarrollo de software.

---

## 1. Especificaciones Técnicas

| Característica | Detalle |
| :--- | :--- |
| **Formato** | 40% (Ultra compacto, 47-48 teclas) |
| **Distribución** | Ortolineal (columnas y filas alineadas en matriz recta) |
| **Sockets** | Intercambiables en caliente (`Hot-swappable`) |
| **Compatibilidad de Switches** | Tipo Cherry MX (soporta variantes de 3 y 5 pines) |
| **Retroiluminación** | RGB completo por tecla (`Per-key RGB`) + LEDs inferiores (`Underglow`) |
| **Conectividad** | Puerto USB Tipo-C integrado |
| **Firmware** | Soporte nativo para `QMK Firmware` y mapeo dinámico vía `VIA` |

---

## 2. Características Principales

* **Distribución Ortolineal:** A diferencia de los teclados escalonados tradicionales, las teclas están alineadas verticalmente en una matriz simétrica. Esto reduce drásticamente el recorrido lateral y la fatiga de los dedos, optimizando la ergonomía durante jornadas largas de tipografía o código.
* **Totalmente Programable (`Firmware Extensible`):** Al contar con soporte para el ecosistema de código abierto `QMK`, permite la configuración de múltiples capas dinámicas (`layers`). Esto facilita el acceso inmediato a bloques numéricos, operadores lógicos y macros personalizadas dentro de una matriz física reducida.
* **Arquitectura Hot-Swap:** La PCB viene equipada con sockets Kailh que permiten la instalación y reemplazo de los interruptores mecánicos a presión. No requiere soldadura, lo que agiliza el mantenimiento y la experimentación con distintos perfiles de fuerza y sonido (como interruptores lineales, táctiles o silenciosos).

---

## 3. Entorno de Compatibilidad

* **Sistemas Operativos:** Compatible a nivel de hardware con kernels **Linux (Fedora/Ubuntu)**, **Windows** y **macOS** sin necesidad de controladores propietarios.
* **Componentes Estándar:** Diseñada para interactuar de forma óptima con perfiles de teclas planos (como la línea `XDA Profile`) para asegurar la uniformidad en la matriz de los interruptores.

---

## 4. Filosofía de Diseño y Ergonomía Custom (Hardware) By Angel Ocampo

El hardware de este build fue seleccionado y construido bajo un enfoque estrictamente **minimalista, ultra compacto y de alta resistencia**, optimizado para el desarrollo de software prolongado en entornos que requieren baja firma acústica.

### Componentes y Sensación Táctil
* **Interruptores (Switches):** Equipado con *Silent Black* lineales. Cuentan con un perfil de resistencia progresiva que exige una fuerza de actuación media-alta para registrar la señal. Esto previene pulsaciones accidentales (*mispclicks*) y ofrece una sensación de tecleo sólida, firme y completamente silenciosa, ideal para mantener la concentración.
* **Keycaps:** Perfil **XDA** en color blanco puro. La altura uniforme de todas las filas complementa perfectamente la naturaleza de la distribución ortolineal, manteniendo una estética limpia, simétrica y de un minimalismo absoluto.

### Arquitectura del Case (Chasis)
* **Construcción:** Fabricado sobre una base de madera aglomerada de alta densidad y forrado exteriormente con **fibra de carbono**. Esta combinación otorga una estructura estructuralmente rígida pero increíblemente ligera.
* **Factor de Forma Ajustado:** El chasis fue diseñado a la medida exacta de la matriz de la PCB, superando sus dimensiones por apenas unos milímetros. Al prescindir de biseles o bordes innecesarios, se maximiza el aspecto compacto y portátil del formato 40%.
* **Estabilidad:** La base cuenta con **6 patas de neopreno antiderrapante** estratégicamente distribuidas. Esto asegura un agarre mecánico perfecto sobre el escritorio, absorbiendo las vibraciones del tecleo pesado sin comprometer su ligereza.

---
*Última revisión técnica: junio 2026*