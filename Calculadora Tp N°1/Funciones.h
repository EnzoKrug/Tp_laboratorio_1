#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief Las opciones y el menu de la calculadora
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return void
 *
 */
void Menu(float,float);

/** \brief Calcular la suma de los numeros ingresados
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return float Devuelve la suma entre los numeros ingresados
 *
 */
float CargarSuma(float,float);

/** \brief Calcular la resta de los numeros ingresados
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return float Devuelve la resta entre los numeros ingresados
 *
 */
float CargarResta(float,float);

/** \brief Calcular la multiplicacion de los numeros ingresados
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return float Devuelve la multiplicacion entre los numeros ingresados
 *
 */
float CargarMultiplicacion(float,float);

/** \brief Calcular la division de los numeros ingresados y
 *         validar que no puede dividir por 0
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return float Devuelve la division entre los numeros ingresados
 *
 */
float CargarDivision(float,float);

/** \brief Calcular el factorial de los numeros ingresados y
 *         validar que no se puede calcular con numeros negativos
 *
 * \param float El primer numero a operar
 * \param float El segundo numero a operar
 * \return int Devuelve el factorial de cada numero
 *
 */
int CargarFactorial(float,float);


#endif // FUNCIONES_H_INCLUDED
