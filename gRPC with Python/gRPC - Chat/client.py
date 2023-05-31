import greet_pb2_grpc
import greet_pb2
import time
import grpc

def get_client_stream_requests():
    while (name == "" or name == null):
        name = input("Username: ")

    hello_request = greet_pb2.HelloRequest(greeting ="Olá",name = name) 
    yield hello_request
    time.sleep(1)   

def run():
    with grpc.insecure_channel("localhost:50051") as channel:
        stud = greet_pb2_grpc.GreeterStub(channel)
        print("1. SayHello -> O_o - Unary")
        print("2. ParrotSaysHello -> O_o - Server On")
        print("3. ChattyClientSaysHello -> o_O - Client On")
        print("4. InteractingHello -> o_O - Both On")
        rpc_call = input("Which RPC would you like to make: ")

        if rpc_call == "1":
            hello_request = greet_pb2.HelloRequest(greeting = "Olá", name = "Lucas")
            hello_reply = stud.SayHello(hello_request)
            print("SayHello Response Received: ")
            print(hello_reply)
        elif rpc_call == "2":
            hello_request = greet_pb2.HelloRequest(greeting = "Olá", name = "Lucas")
            hello_replies = stud.ParrotSaysHello(hello_request)
            for hello_reply in hello_replies:
                print("ParrotSaysHello Response Received: ")
                print(hello_reply)
        elif rpc_call == "3":
            delayed_reply = stub.ChattyClientSaysHello(get_client_stream_requests())
            print("ChattyClientSaysHello Response Received:")
            print(delayed_reply)
        elif rpc_call == "4":
            responses = stub.InteractingHello(get_client_stream_requests())
            for response in responses:
                print("InteractingHello Response Received: ")
                print(response)

if __name__ == "__main__":
        run()