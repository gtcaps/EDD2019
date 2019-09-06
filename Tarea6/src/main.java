public class main {

    public static void main(String[] args) {

        Lista l = new Lista();
        l.insertar(10,35,20,"Proveedor 1");
        l.insertar(5,55,20,"Proveedor 2");
        l.insertar(150,25,20,"Proveedor 3");
        l.insertar(1,5,10,"Proveedor 4");
        l.insertar(20,1,20,"Proveedor 5");
        l.insertar(3,29,30,"Proveedor 6");


        System.out.println("------------------------------- LISTA COMPLETA -------------------------------");
        l.imprimir();

        System.out.println("\n\n");

        System.out.println("------------------------------- LISTA STOCK MINIMO -------------------------------");
        l.copiarListaMin().imprimir();

        System.out.println("\n\n");


        System.out.println("------------------------------- LISTA MAYORES A 100 -------------------------------");
        l.eliminarMayores100();

        l.imprimir();



    }


}


class Nodo{

    public int codigo, stock, stockMinimo;
    public String proveedor;
    Nodo siguiente;

    public Nodo(int codigo, int stock, int stockMinimo, String proveedor){
        this.codigo = codigo;
        this.stock = stock;
        this.stockMinimo = stockMinimo;
        this.proveedor = proveedor;
        siguiente = null;
    }


}

class Lista{

    private Nodo cabeza, cola;

    public Lista(){
        cabeza = cola = null;
    }

    private void insertarFrente(int codigo, int stock, int stockMinimo, String proveedor){
        if(cabeza == null){
            cabeza = cola = new Nodo(codigo, stock, stockMinimo, proveedor);
        }else{
            Nodo nuevoNodo = new Nodo(codigo, stock, stockMinimo, proveedor);
            nuevoNodo.siguiente = cabeza;
            cabeza = nuevoNodo;
        }
    }

    private  void insertarAtras(int codigo, int stock, int stockMinimo, String proveedor){
        if(cabeza == null){
            insertarFrente(codigo, stock, stockMinimo, proveedor);
        }else{
            Nodo nuevoNodo = new Nodo(codigo, stock, stockMinimo, proveedor);
            cola.siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    private void insertarOrdenado(int codigo, int stock, int stockMinimo, String proveedor){
        if(cabeza == null){
            insertarFrente(codigo, stock, stockMinimo, proveedor);
        }else{

            if(codigo < cabeza.codigo){
                insertarFrente(codigo, stock, stockMinimo, proveedor);
            }else if(codigo > cola.codigo){
                insertarAtras(codigo, stock, stockMinimo, proveedor);
            }else{
                Nodo actual = cabeza;
                Nodo anterior = cabeza;

                while(actual != null){
                    if(codigo < actual.codigo){
                        break;
                    }
                    anterior = actual;
                    actual = anterior.siguiente;
                }

                Nodo nuevoNodo = new Nodo(codigo, stock, stockMinimo, proveedor);
                anterior.siguiente = nuevoNodo;
                nuevoNodo.siguiente = actual;
            }
        }
    }


    public void insertar(int codigo, int stock, int stockMinimo, String proveedor){
        insertarOrdenado(codigo, stock, stockMinimo, proveedor);
    }

    public Lista copiarListaMin(){

        if(cabeza != null){
            Lista nuevaLista = new Lista();
            Nodo aux = cabeza;

            while(aux != null){
                if(aux.stock < aux.stockMinimo){
                    nuevaLista.insertar(aux.codigo, aux.stock, aux.stockMinimo, aux.proveedor);
                }
                aux = aux.siguiente;
            }

            return nuevaLista;
        }

        return new Lista();
    }

    public void eliminarMayores100(){
        if(cabeza != null){
            Nodo act = cabeza;
            Nodo ant = null;

            while(act != null){
                if(act.codigo > 100){
                    ant.siguiente = act.siguiente;
                }
                ant = act;
                act = act.siguiente;
            }
        }
    }

    public void imprimir(){
        if (cabeza != null){
            Nodo aux = cabeza;
            while(aux != null){
                System.out.print("-----> Codigo: " + aux.codigo + "  ");
                System.out.print("-----> Stock: " + aux.stock + "  ");
                System.out.print("-----> Stock Minimo: " + aux.stockMinimo + "  ");
                System.out.print("-----> Proveedor: " + aux.proveedor + "  \n");
                aux = aux.siguiente;
            }
        }
    }

}
