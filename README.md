# Projekt układu regulacji wahadła reakcyjnego

Celem projektu było zaprojektowanie i wdrożenie układu regulacji liniowo-kwadratowej **LQR** (ang. *Linear-Quadratic Regulator*) dla fizycznego obiektu **wahadła reakcyjnego** (ang. *Reaction Wheel Pendulum, RWP*). Zadanie polegało na aktywnej stabilizacji układu w **niestabilnym punkcie równowagi** — czyli w odwróconym położeniu pionowym.

## Opis realizacji

Projekt powstał w ramach *Laboratorium Problemowego* i obejmował pełen proces inżynierski od modelowania po wdrożenie:

- ⚙️ **Modelowanie matematyczne** układu w celu dokładnego odwzorowania jego dynamiki,
- 📏 **Identyfikacja parametrów fizycznych** rzeczywistego obiektu,
- 🧪 **Weryfikacja poprawności modelu** na podstawie porównań z zachowaniem rzeczywistego układu,
- 🧠 **Projektowanie, testowanie i implementacja regulatora LQR**, umożliwiającego stabilizację wahadła w pionie.

Proces realizacji wykorzystał technikę **Model-Based Design** w środowisku **MATLAB/Simulink (2015b)**. Uruchomienie systemu w czasie rzeczywistym możliwe było dzięki zastosowaniu **Simulink Real-Time** oraz **karty RT-DAC I/O** zbudowanej w oparciu o układ **FPGA firmy Xilinx**.

## Struktura repozytorium

- 📁 `skrypty/` – zawiera wszystkie skrypty stworzone w języku MATLAB użyte podczas realizacji projektu.
- 📁 `doc/` – zawiera sprawozdanie z projektu.
- 📁 `projekt helikopter/` – zawiera podobny projekt wykonany dla innego obiektu (model helikoptera).

---

> 📌 Projekt stanowi przykład kompleksowego podejścia do projektowania regulatorów dla układów niestabilnych w praktyce inżynierskiej.
