
P 238
14. Here is the code to plot the loss and accuracies using Matplotlib:

# Plot loss over time
plt.plot(eval_indices, train_loss, 'k-')
plt.title('Softmax Loss per Generation')
plt.xlabel('Generation')
plt.ylabel('Softmax Loss')
plt.show()

def plot_loss(d_loss, g_loss, train_options):
    eval_indices = range(0, train_options['epochs'], 1)
    # Plot discriminator and generator loss
    plt.plot(eval_indices, d_loss, 'k-', label='discriminator_loss')
    plt.plot(eval_indices, g_loss, 'r--', label='generator_loss')
    plt.title('discriminator and generator loss')
    plt.xlabel('epochs')
    plt.ylabel('loss')
    plt.legend(loc='upper right')
    plt.show()