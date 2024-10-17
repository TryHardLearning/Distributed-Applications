from concurrent import futures
import time

import grpc
import greet_pb2
import greet_pb2_grpc

class GreeterServicer(greet_pb2_grpc.GreeterServicer):
    def SayHello(self, request,context):
        print("SayHello Request Made:")
        print(request)
        hello_reply = greet_pb2.HelloReply()
        hello_reply.message = f"{request.name}: {request.greeting}."
        return hello_reply

    def ParrotSaysHello(self, request,context):
        print("ParrotSaysHello Request Mode:")
        print(request)
        for i in range(3):
            hello_reply = greet_pb2.HelloReply()
            hello_reply.message = f"{request.name}: {request.greeting}."
            yield hello_reply
            time.sleep(1)
    
    def ChattyClientSaysHello(self, request,context):
        return super(GreeterServicer, self).ChattyClientSaysHello(request,context)
    
    def InteractingHello(self, request,context):
        return super(GreeterServicer, self).InteractingHello(request,context)

def serve():
        server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        greet_pb2_grpc.add_GreeterServicer_to_server(GreeterServicer(),server)
        server.add_insecure_port("localhost:50051")
        server.start()
        server.wait_for_termination()

if __name__ == "__main__":
        serve()