import { ActivityIndicator, StyleSheet, Text, TouchableOpacity, View } from 'react-native';
import { COLORS, SIZES } from '../constants';

import DoorCard from './cards/DoorCard';

import useFetch2 from '../hook/useFetch2';


const Doors = ( {url} ) => {
	//const router = useRouter();
    
    const { data, isLoading, error, refetch } = useFetch2('')


	return (
	
        <View style={styles.container}>

            <View style={styles.header}>
                {/* Titulo */}
                <Text style={styles.headerTitle}>Doors</Text>
                {/* Boton de Sync */}
                <TouchableOpacity
                    onPress={() => refetch()}
                >
                   <Text>Sync</Text>
                </TouchableOpacity>
            </View>
            {/* Instrucciones */}
            <Text style={styles.headerInfo}>Press each to change state.</Text>
            {/* Contenedor de las cards */}
            <View style={styles.containerCards}>
                {isLoading ? ( /* Mientras carga */
                    <ActivityIndicator size='large' colors={COLORS.primary} />
                    ) : error ? ( /* Si hay un error */
                        <Text>Something went wrong</Text>
                    ) : ( /* Si hay datos */
                        <View>
                            {data.map((item, index) => (
                                <View key={index}>
                                    {item.controlElement === 'Puerta' ? (
                                    <DoorCard key={index}
                                        item={item}
                                        ubication={`Puerta${index+1}`}
                                    />
                                    ) : (
                                    null
                                    )
                                    }
                                </View>
                                ))}
                        </View> 
                    )
                }       
            </View>
        </View>
    
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: SIZES.xLarge,
    },
    containerCards: {
        marginTop: SIZES.small,
    },
    header: {
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "center",
    },
    header2: {
        width: "100%",
		backgroundColor: COLORS.white,
        paddingVertical: 20
    },
    headerTitle: {
        fontSize: SIZES.xLarge,
        fontWeight: 'bold',
        color: COLORS.primary,
        marginBottom: 5,
      },
    headerInfo: {
        fontSize: SIZES.medium,
        color: COLORS.secondary,
      },
});

export default Doors;
