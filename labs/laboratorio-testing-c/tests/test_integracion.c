#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void) {
    printf("\n[integracion: compra completa con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Leche", 350, 2};  /* 700 */
    Producto p2 = {"Pan", 200, 3};    /* 600 */
    Producto p3 = {"Queso", 1500, 1}; /* 1500 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    ASSERT_IGUAL(3, carrito_contar(&c));

    int total = carrito_total(&c);
    ASSERT_IGUAL(2800, total);

    int total_desc = carrito_descuento(total, 10);
    ASSERT_IGUAL(2520, total_desc);
}

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    /* test_agregar_hasta_llenar();  */
    RESUMEN();
    return EXIT_CODE();
}
