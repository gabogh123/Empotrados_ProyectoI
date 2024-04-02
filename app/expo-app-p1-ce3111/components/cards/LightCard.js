import { StyleSheet, Text, TouchableOpacity, View } from 'react-native';
import { COLORS, SIZES } from '../../constants';
import axios from 'axios';


const LightCard = ( {id, item, ubication, state, url, refetchData} ) => {

    const handleCardPress = () => {
        console.log('Pressed LightCard for', ubication);

        // Se hace el POST para cambiar el estado de la luz
        toggle();
        // Para actualizar los datos
        refetchData();
    };

    const toggle = async () => {

        const options = {
            method: 'POST',
            url: `${url}/${ubication.toLowerCase()}`
        };

        try {
            const response = await axios.request(options);
            console.log('Toggle for', ubication,  `: (${url}/${ubication.toLowerCase()})`);
            console.log(response.data);
        } catch (error) {
            console.error(error);
            alert('POST can not be done');
        }
    }

	return (
        <TouchableOpacity
            style={styles.container}
            onPress={() => handleCardPress(item)}
        >
            <View style={styles.header}>
                <Text style={styles.element}>{`${item.controlElement} ${item.id}`}</Text>
                <Text style={styles.state}>{item.state}</Text>
            </View>
        </TouchableOpacity>
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: 10,
        marginBottom: 10
    },
    header: {
        flexDirection: "collumn",
        justifyContent: "space-between",
        alignItems: "flex-start",
        marginHorizontal: 30
    },
    element: {
        fontSize: SIZES.large,
        color: COLORS.primary,
    },
    state: {
        fontSize: SIZES.medium,
        color: COLORS.secondary,
    },
    cardsContainer: {
        marginTop: SIZES.medium,
    },
});

export default LightCard;
